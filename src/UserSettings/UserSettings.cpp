#include "UserSettings.hpp"
#include "Cool/i18n/i18n.hpp"
#include "Cool/ImGui/ImGuiExtras.h"

namespace Lab {

auto UserSettings::imgui() -> bool
{
    bool b = false;

    Cool::ImGuiExtras::separator_text(Cool::tr("Save As"));
    b |= imgui_save_as_behaves_as_save_backup();

    if (b)
        _serializer.save();
    return b;
}

auto UserSettings::imgui_save_as_behaves_as_save_backup() -> bool
{
    bool const b = Cool::ImGuiExtras::toggle(Cool::i18n::label("\"Save As\" behaves as a \"Save Backup\"").c_str(), &save_as_behaves_as_save_backup);
    Cool::ImGuiExtras::help_marker(Cool::tr("When this is enabled, Save As will not make you switch to the new project you just saved. For example, if you are working on \"My Project\" and do a Save As \"V1\", you will stay on the \"My Project\" project (whereas if this option is disabled, you would now be working on \"V1\").\nYou will notice the name changing in the window's title bar if you switch to a different project."));
    return b;
}

} // namespace Lab
