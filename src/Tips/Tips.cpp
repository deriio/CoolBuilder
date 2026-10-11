#include "Tips.h"
#include "Cool/i18n/i18n.hpp"
#include "Cool/ImGui/IcoMoonCodepoints.h"
#include "Cool/Input/CTRL_OR_CMD.hpp"

namespace Lab {

static auto all_tips_russian() -> Cool::Tips
{
    static constexpr auto tips = std::array{
        "Наши [видеоуроки на YouTube](https://youtu.be/FK1sMPgcE4Q?list=PLuMMMaL5kN3mG6fSeSYTqC-sc_OTX3unQ) помогут начать работу с Coollab.",
        "Ноды можно скопировать (" CTRL_OR_CMD "+C) и отправить другу как текст, а он вставит их в свой Coollab (" CTRL_OR_CMD "+V). Так же можно переносить ноды между своими проектами.",
        "Цветовую тему можно сменить в меню \" " ICOMOON_COG "Настройки\", и даже создать свою!",
        "Нажмите " CTRL_OR_CMD "+E, чтобы быстро экспортировать изображение с текущими настройками экспорта.",
        "Нажмите F в окне \" " ICOMOON_TREE "Ноды\", чтобы показать все ноды целиком.",
        CTRL_OR_CMD "+клик по слайдеру позволяет ввести значение вручную (и даже выйти за пределы слайдера!).",
        "В виджете угла или направления зажмите SHIFT, чтобы привязываться к точным углам.",
        "Зажмите ALT при прокрутке колёсика в окне \" " ICOMOON_IMAGE "Просмотр\", чтобы масштабировать относительно центра, а не курсора.",
        "Чтобы повернуть 2D-камеру, зажмите SHIFT и прокрутите колёсико мыши над окном \" " ICOMOON_IMAGE "Просмотр\".",
        "Щёлкните правой кнопкой по виджету, чтобы изменить его настройки (диапазон слайдера и т.п.).",
        "Если вам понравились найденные параметры ноды, сохраните их как пресет. Эта возможность находится внизу окна \" " ICOMOON_EQUALIZER "Инспектор\", когда выбрана нода.",
        "При копировании нод зажмите SHIFT, чтобы скопировать и входящие связи, даже если они идут от нод, которые не копируются.",
        "История отмены (" CTRL_OR_CMD "+Z / " CTRL_OR_CMD "+Y) сохраняется даже после перезапуска Coollab! Её размер настраивается в меню \" " ICOMOON_COG "Настройки\".",
        "Нажмите ESCAPE, чтобы закрыть эти окна.",

        // Bonus ImGui tips
        "Перетащите кнопку меню окна (стрелка в правом верхнем углу), чтобы переместить сразу все вкладки.",
        "Зажмите SHIFT, чтобы отключить прикрепление окон. Удобно, когда вы двигаете окно, а оно всё время пристыковывается.",
        "Дважды щёлкните по правому нижнему углу плавающего окна, чтобы подогнать его размер под содержимое.",
        "TAB и SHIFT+TAB переключают между полями ввода в окне.",
        R"STR(Несколько полезных сочетаний клавиш:
  * При вводе текста:
    * )STR" CTRL_OR_CMD R"STR(+Влево/Вправо — переход по словам.
    * )STR" CTRL_OR_CMD R"STR(+A или двойной клик — выделить всё.
    * )STR" CTRL_OR_CMD R"STR(+X/C/V — вырезать/копировать/вставить.
    * )STR" CTRL_OR_CMD R"STR(+Z, )STR" CTRL_OR_CMD R"STR(+Y — отменить/повторить.
    * ESCAPE — отменить ввод.
  * Навигация с клавиатуры:
    * )STR" CTRL_OR_CMD R"STR(+TAB — выбрать окно.
    * Стрелки — перемещение внутри окна.
    * ENTER — активировать виджет.
    * ESCAPE — деактивировать виджет, закрыть всплывающее окно, выйти из вложенного окна.
    * ALT — перейти в меню окна.
)STR",
    };

    return tips;
}

auto all_tips() -> Cool::Tips
{
    if (Cool::i18n::current_language() == Cool::i18n::Language::Russian)
        return all_tips_russian();

    static constexpr auto tips = std::array{
        "Our [Youtube tutorials](https://youtu.be/FK1sMPgcE4Q?list=PLuMMMaL5kN3mG6fSeSYTqC-sc_OTX3unQ) can help you get started with Coollab.",
        "You can copy your nodes (" CTRL_OR_CMD "+C) and send them as text to a friend, who can then paste them in their instance of Coollab (" CTRL_OR_CMD "+V). You can also paste them in another project of yours.",
        "You can change the color theme in the \" " ICOMOON_COG "Settings\" menu, and even create your own!",
        "Use " CTRL_OR_CMD "+E to quickly export an image with the current export settings",
        "Use F in the \" " ICOMOON_TREE "Nodes\" window to focus the view on the nodes.",
        CTRL_OR_CMD "+click on a slider to input a value manually. (It also allows you to bypass the bounds of the slider!).",
        "In an angle or direction widget, hold SHIFT to snap to precise angles.",
        "Press ALT while scrolling in the \" " ICOMOON_IMAGE "View\" to zoom relative to the center of the view, instead of relative to the position of the mouse.",
        "You can rotate the 2D camera by holding SHIFT and scrolling the mouse wheel over the \" " ICOMOON_IMAGE "View\".",
        "Right-click on a widget to edit its metadata (range of a slider, etc.).",
        "You can save your own presets for a node if you like the parameters (and metadata) you found. You will find this option at the bottom of the the \" " ICOMOON_EQUALIZER "Inspector\" when a node is selected.",
        "When copying nodes, you can press SHIFT to copy links going into the copied nodes, even if the link is starting from a node that is not copied.", // This one would really need a gif to explain it more clearly.
        "The undo-history (" CTRL_OR_CMD "+Z / " CTRL_OR_CMD "+Y) is preserved even when you close and re-open Coollab! You can control its size in the \" " ICOMOON_COG "Settings\" menu.",
        "You can press ESCAPE to close these popups.",

        // Bonus ImGui tips
        "Drag from the window menu button (the arrow button in the upper-right corner) to move all tabs at once.",
        "You can hold SHIFT to disable docking. Useful when you try to move a window around and docking gets in your way.",
        "Double-click on the lower-right corner of a floating window to fit its size to its content.",
        "Use TAB and SHIFT+TAB to cycle through the keyboard-editable fields of a window.",
        R"STR(Here are a few useful shortcuts:
  * While inputting text:
    * )STR" CTRL_OR_CMD R"STR(+Left/Right to word jump.
    * )STR" CTRL_OR_CMD R"STR(+A or double-click to select all. 
    * )STR" CTRL_OR_CMD R"STR(+X/C/V to use clipboard cut/copy/paste. 
    * )STR" CTRL_OR_CMD R"STR(+Z, )STR" CTRL_OR_CMD R"STR(+Y to undo/redo. 
    * ESCAPE to revert.
  * To navigate with the keyboard:
    * )STR" CTRL_OR_CMD R"STR(+TAB to select a window.
    * Arrow keys to navigate inside a window.
    * ENTER to activate a widget.
    * ESCAPE to deactivate a widget, close popup, exit child window.
    * ALT to jump to the menu of a window.
)STR",
    };

    return tips;
}

} // namespace Lab