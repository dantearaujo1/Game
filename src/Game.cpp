#include "../include/Game.hpp"
#include "../include/Managers/SceneManager.hpp"

Game::Game() : m_sceneManager(nullptr){}

Game::~Game() {}

void Game::init(const std::string &title, uint32_t width, uint32_t height) {
  m_window.create(sf::VideoMode(width, height), title);
  ImGui::SFML::Init(m_window);
  m_sceneManager = new SceneManager(this);
  m_sceneManager->init(this);
  m_debug = false;
}

void Game::handleInput() {
  while (m_window.pollEvent(m_event)) {

    // Process all ImGUI Events before everything;
    ImGui::SFML::ProcessEvent(m_event);

    if (m_event.type == sf::Event::Closed) {
      m_window.close();
    }
    if (m_event.type == sf::Event::KeyPressed) {
      if (m_event.key.code == sf::Keyboard::Escape) {
        m_window.close();
      }
    }

    m_sceneManager->handleInput(m_event);

  }
}

void Game::render() {

  m_window.clear(sf::Color::Black);

  // Render Scenes
  m_sceneManager->render(m_window);


  // Render ImGUI after everything
    ImGui::SFML::Render(m_window);

  // Clear screen
  m_window.display();

}

void Game::update(float dt, float target_FPS) {

  m_sceneManager->update(dt, target_FPS);
}

void Game::run() {

  float TARGET_UPS = 60.0f;

  sf::Time accumulator;
  sf::Time lastTime = sf::seconds(0);
  sf::Time newTime = sf::seconds(0);
  ;
  sf::Time ups = sf::seconds(1 / TARGET_UPS);

  while (m_window.isOpen()) {

    lastTime = newTime;
    newTime = m_clock.getElapsedTime();
    m_deltaTime = newTime - lastTime;
    accumulator += m_deltaTime;

    handleInput();

    while (accumulator > ups) {
      accumulator -= ups;
      update(ups.asSeconds(), TARGET_UPS);
    }
    // ImGUI must be updated everytime
    ImGui::SFML::Update(m_window, ups);
    render();

    //TESTING
    // static float x = 98;
    // static float z = 200;
    // static float duration = 10.0f;
    // static float elapsed = 0.0f;
    //
    // float lerp = x + (z - x) * elapsed/duration;
    // elapsed += ups.asSeconds();
    // if (elapsed > duration){lerp = z;}
    //
    // sf::RectangleShape shape{sf::Vector2f(32,32)};
    // shape.setPosition( lerp,0);
    // shape.setFillColor(sf::Color::White);
    // std::cout << "Lerp: " << lerp << " X: " << x << " Elapsed: " << elapsed << std::endl;
    // std::cout << "DeltaTime: " << ups.asSeconds() << std::endl;
    // m_window.clear(sf::Color::Black);
    // m_window.draw(shape);
  }
  ImGui::SFML::Shutdown();
}
