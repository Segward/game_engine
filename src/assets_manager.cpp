#include <assets_manager.hpp>

AssetsManager& AssetsManager::instance() {
  static AssetsManager assets_manager;
  return assets_manager;
}
