#include "../../include/Scenes/GameScene.hpp"
#include "../../include/Managers/SceneManager.hpp"

#include "../../include/Game.hpp"

#include "imgui.h"
#include <iterator>
#include <type_traits>
#include <utility>
#include <random>


extern std::map<TILETYPE, const std::string> tileTypeMap;

GameScene::GameScene(SceneManager *manager) : Scene(manager), m_tileManager(m_director->getApp(),m_director->getTextureManager()) {

}
GameScene::~GameScene() {
  m_director = nullptr;
}

bool GameScene::init() {

  m_aSystem.textureManager = m_director;
  if(!loadAnimations()){
    return false;
  }
  m_eFactory.createPlayer(1);
  // m_eFactory.createPlayer(2);

  // Procedural map creation
  std::random_device dvc;
  for (int i = 0; i < 19; i++){
    for (int j = 0; j < 25; j++){
      if ((i + j) % 2 == 0){
        if (dvc() % 7 == 0){
          m_tileManager.createTile(dvc()%2+3, j*32,i*32,32,32,"map", TILETYPE::FLOOR);
          continue;
        }
        m_tileManager.createTile(1, j*32,i*32,32,32,"map", TILETYPE::FLOOR);
      }
      else{

        m_tileManager.createTile(1, j*32,i*32,32,32,"map", TILETYPE::FLOOR);
      }
    }
  }


  return true;
}

void GameScene::handleInput(sf::Event e) {

  if (e.type == sf::Event::KeyPressed){
    if (e.key.code == sf::Keyboard::Key::F1){
      m_director->getApp()->setDebug(!m_director->getApp()->isDebugActivated());
    }
  }

  m_cSystem.handleInput(e);
}

void GameScene::render(sf::RenderWindow &window) {
  m_tileManager.render(window);
  m_rSystem.render(window);


  // THESE LINES ARE FOR GUI USING IMGUI =====================================
  // Getting the style variable of ImGui
  static ImGuiStyle& style = ImGui::GetStyle();

  style.WindowMinSize = ImVec2(500,400);
  style.Colors[ImGuiCol_WindowBg] = ImColor(0,0,0,255);

  // This Freezes the window in a position
  ImGui::SetNextWindowPos(sf::Vector2i(0 + window.getSize().x/2,0 + window.getSize().y/2),ImGuiCond_Once, sf::Vector2f(0.5f,0.5f));

  if (m_director->getApp()->isDebugActivated()) {

    if(ImGui::Begin("GUI", nullptr)){

      const char* options[] = {"Game Information Debug", "Tileset Editor"};
      static int option_current_idx = 0;
      const char* combo_preview_value = options[option_current_idx];

      ImGui::SetNextItemWidth(256);
      if(ImGui::BeginCombo("MenuCombo", combo_preview_value)){

        for (int n = 0; n < IM_ARRAYSIZE(options); n++){
          const bool is_selected = (option_current_idx == n);
          if (ImGui::Selectable(options[n], is_selected)){
            option_current_idx = n;
          }
          if (is_selected){
            ImGui::SetItemDefaultFocus();
          }
        }

        ImGui::EndCombo();
      }

      if (option_current_idx == 0){

          ImGui::Text("Mouse coordinates: %ix , %iy", sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
          ImGui::Text("Tile coordinates: %ix , %iy", sf::Mouse::getPosition(window).x/32, sf::Mouse::getPosition(window).y/32);
        }

      if (option_current_idx == 1){

          auto helper = m_tileManager.getTextureHelper();
          static auto tileID = helper.getTileID(0,0);
          const auto tileX = helper.getTilesLength().x;
          const auto tileY = helper.getTilesLength().y;
          const auto tileSize = helper.getTileSize().x;
          const auto tilemap = m_director->getTexture("map");
          auto draw_list = ImGui::GetWindowDrawList();

          sf::Vector2f tilesetImagePos = ImGui::GetCursorScreenPos();
          ImGui::Image(*tilemap, (ImVec2) m_director->getTexture("map")->getSize());


          // Drawing vertically lines inside or tileset
          for (int x = 0; x <= tileX; x++){
            draw_list->AddLine(ImVec2(tilesetImagePos.x + x * tileSize, tilesetImagePos.y), ImVec2(tilesetImagePos.x + x * tileSize, helper.getTextureSize().y),ImColor(255,0,0));
          }
          // Drawing  lines horizontally inside or tileset
          for (int y = 0; y <= tileY; y++){
            draw_list->AddLine(ImVec2(tilesetImagePos.x , tilesetImagePos.y + y * tileSize), ImVec2(tilesetImagePos.x + helper.getTextureSize().x, tilesetImagePos.y + y * tileSize),ImColor(255,0,0));
          }

          // Checking if Last Appended Item is Hovered (IMAGE) and Clicked with relative Mouse Position
          if (ImGui::IsItemHovered()){
            if (ImGui::IsMouseClicked(0)){
              // Getting the Mouse Position relative to the TilesetImage as we click
              const auto relMousePos = static_cast<sf::Vector2i>(sf::Vector2f(ImGui::GetMousePos()) - tilesetImagePos);
              // Getting the Unique ID from the tileset as we click
              tileID = helper.getTileID(relMousePos.x,relMousePos.y);
            }
          }
          // Now that we have our tileID we can highlight our selected Tile
          const auto tileRect = static_cast<sf::FloatRect>(helper.getTileByID(tileID));

          sf::Vector2f selectedTileTL = sf::Vector2f(helper.getTileByID(tileID).left, helper.getTileByID(tileID).top);
          sf::Vector2f selectedTileBR = selectedTileTL + static_cast<sf::Vector2f>(helper.getTileSize());

          selectedTileTL += tilesetImagePos;
          selectedTileBR += tilesetImagePos;

          draw_list->AddRect(selectedTileTL, selectedTileBR, ImColor(0,255,0));

          // We Need to Place Selected Tile In a BigPicture
          auto tileImagePos = tilesetImagePos;

          sf::Sprite sprite;
          sprite.setTexture(*tilemap);
          sprite.setTextureRect(static_cast<sf::IntRect>(tileRect));
          sprite.scale(4.0f,4.0f);

          int padding = 50;
          tileImagePos.x += helper.getTextureSize().x + padding;
          // Stay at a fixed size even if we scrollDown.
          tileImagePos.y += ImGui::GetScrollY();
          ImGui::SetCursorScreenPos(tileImagePos);
          ImGui::Image(sprite);


          // Placing some information after the tileImage
          tileImagePos.x += ImGui::GetCursorPosX() - 5;
          tileImagePos.y += sprite.getGlobalBounds().height;
          ImGui::SetCursorScreenPos(tileImagePos);
          ImGui::Text("Selected tileID: %i", tileID);
          // ImGui::NewLine();
          tileImagePos.y += ImGui::GetTextLineHeightWithSpacing();
          ImGui::SetCursorScreenPos(tileImagePos);
          ImGui::Text("Tile Type: %s", tileTypeMap[m_tileManager.getTile(tileID)->getType()]);
        }
      }


  // ABOVE LINES ARE FOR GUI USING IMGUI =====================================

    ImGui::End();
  }

}

void GameScene::update(float dt, float ups) {
  m_cSystem.update(dt, ups); // Controller System
  m_mSystem.update(dt, ups); // Movement System

  // Systems that update Render to window something
  m_tileManager.update(dt,ups); // TileManager
  m_rSystem.update(dt, ups); // Render System
  m_aSystem.update(dt, ups); // Animation System
}
bool GameScene::loadAnimations(){
  m_aFactory.createAnimation("child_walking_left");
  m_aFactory.createAnimation("child_walking_right");
  m_aFactory.createAnimation("child_walking_north");
  m_aFactory.createAnimation("child_walking_south");

  m_aFactory.addFrames("child_walking_north", 5, 0,0,32,64);
  m_aFactory.addFrames("child_walking_south", 5, 0,64,32,64);
  m_aFactory.addFrames("child_walking_left", 8, 0,128,32,64);
  m_aFactory.addFrames("child_walking_right", 8, 0,192,32,64);

  return true;
}
