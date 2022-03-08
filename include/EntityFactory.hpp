#pragma once
#include "vendors/entt/entt.hpp"
#include "SFML/Graphics.hpp"

#include "Managers/AnimationManager.hpp"
#include "Managers/SceneManager.hpp"
#include "ECS/Components/Components.hpp"

class EntityFactory
{
public:
  EntityFactory(entt::registry* ecs = nullptr, SceneManager* director = nullptr, AnimationFactory* afct = nullptr);
  EntityFactory(EntityFactory &&) = default;
  EntityFactory(const EntityFactory &) = default;
  EntityFactory &operator=(EntityFactory &&) = default;
  EntityFactory &operator=(const EntityFactory &) = default;
  ~EntityFactory();

    entt::entity createPlayer(int id);

private:
    entt::registry* m_ecs;
    AnimationFactory* m_animationFactory;
    SceneManager* m_director;
};

