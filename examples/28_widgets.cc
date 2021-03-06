/*
 * Gamedev Framework (gf)
 * Copyright (C) 2016-2018 Julien Bernard
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */
#include <cstdlib>
#include <cstdio>

#include <deque>
#include <iostream>
#include <vector>

#include <gf/Color.h>
#include <gf/Event.h>
#include <gf/Font.h>
#include <gf/RenderWindow.h>
#include <gf/Shapes.h>
#include <gf/Sprite.h>
#include <gf/Text.h>
#include <gf/Texture.h>
#include <gf/TextureAtlas.h>
#include <gf/WidgetContainer.h>
#include <gf/Widgets.h>
#include <gf/Window.h>

int main() {
  gf::Window window("28_widgets", { 640, 480 }, ~gf::WindowHints::Resizable);
  gf::RenderWindow renderer(window);

  gf::Font font;

  if (!font.loadFromFile("assets/DejaVuSans.ttf")) {
    return EXIT_FAILURE;
  }

  gf::TextureAtlas atlas;

  if (!atlas.loadFromFile("assets/ui.xml")) {
    return EXIT_FAILURE;
  }

  gf::Texture texture;

  if (!texture.loadFromFile("assets/ui.png")) {
    return EXIT_FAILURE;
  }

  atlas.setTexture(texture);

  std::cout << "Gamedev Framework (gf) example #28: widgets\n";
  std::cout << "This example shows some game widgets.\n";
  std::cout << "How to use:\n";
  std::cout << "\tUp/Down: Navigate through widgets\n";
  std::cout << "\tReturn: Activate the selected widget\n";

  gf::WidgetContainer widgets;

  gf::Text start("Start", font, 25);
  start.setPosition({ 50.0f, 50.0f });
  start.setAnchor(gf::Anchor::TopLeft);

  gf::TextWidget startWidget(start);
  startWidget.setTextOutlineThickness(1.0f);
  startWidget.setCallback([]() { std::cout << "Start!\n"; });
  widgets.addWidget(startWidget);

  gf::Text options("Options", font, 25);
  options.setPosition({ 50.0f, 80.0f });
  options.setAnchor(gf::Anchor::TopLeft);

  gf::TextWidget optionsWidget(options);
  optionsWidget.setTextOutlineThickness(1.0f);
  optionsWidget.setCallback([]() { std::cout << "Options!\n"; });
  widgets.addWidget(optionsWidget);

  gf::Text disabled("Disabled", font, 25);
  disabled.setPosition({ 50.0f, 110.0f });
  disabled.setAnchor(gf::Anchor::TopLeft);

  gf::TextWidget disabledWidget(disabled);
  disabledWidget.setTextOutlineThickness(1.0f);
  disabledWidget.setCallback([]() { std::cout << "Disabled!\n"; });
  disabledWidget.setDisabled();
  widgets.addWidget(disabledWidget);

  gf::Text quit("Quit", font, 25);
  quit.setPosition({ 50.0f, 140.0f });
  quit.setAnchor(gf::Anchor::TopLeft);

  gf::TextButtonWidget quitWidget(quit);
  quitWidget.setTextOutlineThickness(1.0f);
  quitWidget.setBackgroundOutlineThickness(1.0f);
  quitWidget.setRadius(2.0f);
  quitWidget.setPadding(4.0f);
  quitWidget.setCallback([]() { std::cout << "Quit!\n"; });
  widgets.addWidget(quitWidget);

  gf::Text transformed("Transformed", font, 25);
  transformed.setPosition({ 50.0f, 180.0f });
  transformed.setRotation(gf::Pi / 4);
  transformed.setAnchor(gf::Anchor::TopLeft);
  transformed.setScale({ 1.0f , 0.8f });

  gf::TextButtonWidget transformedWidget(transformed);
  transformedWidget.setTextOutlineThickness(1.0f);
  transformedWidget.setBackgroundOutlineThickness(1.0f);
  transformedWidget.setRadius(2.0f);
  transformedWidget.setPadding(4.0f);
  transformedWidget.setCallback([]() { std::cout << "Rotated and scaled!\n"; });
  widgets.addWidget(transformedWidget);

  gf::Text disabledAgain("Disabled again", font, 25);
  disabledAgain.setPosition({ 50.0f, 320.0f });
  disabledAgain.setAnchor(gf::Anchor::TopLeft);

  gf::TextButtonWidget disabledAgainWidget(disabledAgain);
  disabledAgainWidget.setTextOutlineThickness(1.0f);
  disabledAgainWidget.setBackgroundOutlineThickness(1.0f);
  disabledAgainWidget.setRadius(2.0f);
  disabledAgainWidget.setPadding(4.0f);
  disabledAgainWidget.setDisabled();
  disabledAgainWidget.setCallback([]() { std::cout << "Disabled again!\n"; });
  widgets.addWidget(disabledAgainWidget);

  gf::Vector2f spritePosition(300.0f, 50.0f);
  gf::Sprite defaultSprite(texture, atlas.getTextureRect("grey_button04.png"));
  defaultSprite.setPosition(spritePosition);
  gf::Sprite selectedSprite(texture, atlas.getTextureRect("grey_button02.png"));
  selectedSprite.setPosition(spritePosition);
  gf::Sprite disabledSprite(texture, atlas.getTextureRect("grey_button05.png"));
  disabledSprite.setPosition(spritePosition);

  gf::SpriteWidget spriteWidget(defaultSprite, selectedSprite, disabledSprite);
  spriteWidget.setCallback([]() { std::cout << "Sprite!\n";  });
  widgets.addWidget(spriteWidget);

  gf::Vector2f choicePosition(300.0f, 100.0f);
  gf::Sprite emptySprite(texture, atlas.getTextureRect("grey_box.png"));
  emptySprite.setPosition(choicePosition);
  gf::Sprite chosenSprite(texture, atlas.getTextureRect("grey_boxCheckmark.png"));
  chosenSprite.setPosition(choicePosition);

  gf::ChoiceSpriteWidget choiceWidget(emptySprite, chosenSprite);
  choiceWidget.setCallback([&choiceWidget]() { std::cout << (choiceWidget.isChosen() ? "Chosen\n" : "Empty\n"); });
  widgets.addWidget(choiceWidget);

  gf::Clock clock;
  renderer.clear(gf::Color::White);

  while (window.isOpen()) {
    gf::Event event;

    while (window.pollEvent(event)) {
      switch (event.type) {
        case gf::EventType::Closed:
          window.close();
          break;

        case gf::EventType::KeyPressed:
          switch (event.key.keycode) {
            case gf::Keycode::Escape:
              window.close();
              break;

            case gf::Keycode::Up:
              widgets.selectPreviousWidget();
              break;

            case gf::Keycode::Down:
              widgets.selectNextWidget();
              break;

            case gf::Keycode::Return:
              widgets.triggerAction();
              break;

            default:
              break;
          }
          break;

        case gf::EventType::MouseMoved:
          widgets.pointTo(renderer.mapPixelToCoords(event.mouseCursor.coords));
          break;

        case gf::EventType::MouseButtonPressed:
          widgets.pointTo(renderer.mapPixelToCoords(event.mouseButton.coords));
          widgets.triggerAction();
          break;

        default:
          break;
      }
    }

    renderer.clear();
    widgets.render(renderer);
    renderer.display();
  }

  return 0;
}
