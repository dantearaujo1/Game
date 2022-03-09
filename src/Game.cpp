#include "../include/Game.hpp"

Game::Game() {}

Game::~Game() {}

void Game::init(const std::string &title, uint32_t width, uint32_t height) {
  m_window.create(sf::VideoMode(width, height), title);
  ImGui::SFML::Init(m_window);
  m_sceneManager.init();
}

void Game::handleInput() {
  while (m_window.pollEvent(m_event)) {
    // Process all ImGUI Events before everything;
    ImGui::SFML::ProcessEvent(m_event);
    if (m_event.type == sf::Event::Closed) {
      m_window.close();
      std::cout << "Window closed" << std::endl;
      std::cout << "CLOSED closed" << std::endl;
    }
    if (m_event.type == sf::Event::KeyPressed) {
      std::cout << "Event - KeyPressed: " << m_event.key.code << std::endl;
      if (m_event.key.code == sf::Keyboard::Escape) {
        std::cout << "Window closed" << std::endl;
        m_window.close();
      }
    }
    m_sceneManager.handleInput(m_event);
  }
}

void Game::render() {

  // Render Scenes
  m_sceneManager.render(m_window);

  // Render ImGUI AFTER everything
  ImGui::Begin("My First tool");
  ImGui::End();

  // Clear screen
  m_window.clear(sf::Color::Black);
  ImGui::SFML::Render(m_window);
  m_window.display();

}

void Game::update(float dt, float target_FPS) {

  dt = dt * target_FPS;
  m_sceneManager.update(dt, target_FPS);
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
      update(ups.asSeconds(), TARGET_UPS);
      accumulator -= ups;
    }
    // ImGUI must be updated everytime
    ImGui::SFML::Update(m_window, m_deltaTime);
    render();
  }
  ImGui::SFML::Shutdown();
}
