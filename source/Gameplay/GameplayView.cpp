#include "../../header/Gameplay/GameplayView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Graphics/GraphicService.h"

namespace Gameplay
{
    using namespace UI::UIElement;
    using namespace Global;

    GameplayView::GameplayView() : gameplay_controller(/* Initialize gameplay_controller here */) {
        background_image = new ImageView();
    }

    GameplayView::~GameplayView() {
        delete background_image;
    }

    void GameplayView::initialize() {
        initializeBackgroundImage();
    }

    void GameplayView::initializeBackgroundImage() {
        sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

        background_image->initialize(Config::background_texture_path,
            static_cast<float>(game_window->getSize().x), // Convert to float to avoid loss of data
            static_cast<float>(game_window->getSize().y), // Convert to float to avoid loss of data
            sf::Vector2f(0, 0));

        background_image->setImageAlpha(background_alpha);
    }

    void GameplayView::update() {
        background_image->update();
    }

    void GameplayView::render() {
        background_image->render();
    }
}
