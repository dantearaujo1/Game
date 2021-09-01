#pragma once

#include "../../vendors/entt/entt.hpp"
#include "../Components/Components.hpp"

class CSystem {
public:
  CSystem(entt::registry *manager){m_entityManager = manager;};
  ~CSystem(){};

  virtual bool init(){return true;};
  virtual void update(){};

protected:
  entt::registry *m_entityManager;
};
