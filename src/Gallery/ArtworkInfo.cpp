#include "ArtworkInfo.h"
#include "Cool/i18n/i18n.hpp"
#include <imgui.h>

namespace Lab {

auto ArtworkInfo::imgui() -> bool
{
    bool b = false;
    b |= ImGui::InputText(Cool::i18n::label("Title").c_str(), &title);
    b |= ImGui::InputText(Cool::i18n::label("Description").c_str(), &description);
    return b;
}

} // namespace Lab