#include "AuthorInfo.h"
#include "Cool/i18n/i18n.hpp"
#include <imgui.h>
#include "Cool/ImGui/ImGuiExtras.h"

namespace Lab {

auto AuthorInfo::imgui() -> bool
{
    bool b = false;
    b |= ImGui::InputText(Cool::i18n::label("Your name").c_str(), &name);
    b |= ImGui::InputText(Cool::i18n::label("Your link").c_str(), &link);
    Cool::ImGuiExtras::help_marker(Cool::tr("An optional link for people to find you or your work: it can be your portfolio, linktree, Instagram, etc."));
    return b;
}

} // namespace Lab