#include "MeshingSettings.hpp"
#include "Cool/i18n/i18n.hpp"
#include "Cool/ImGui/ImGuiExtras.h"

namespace Lab {

void MeshingSettings::imgui()
{
    // TODO(Meshing) GUI for the other settings
    if (ImGui::InputScalarN(Cool::i18n::label("Samples Count").c_str(), ImGuiDataType_U32, glm::value_ptr(samples_count), 3, nullptr, nullptr, "%u"))
    {
        // Ensure that the sampling count is at least 1
        samples_count = glm::max(samples_count, glm::uvec3(1));
    }
    Cool::ImGuiExtras::help_marker(Cool::tr("The number of samples to take along each axis of the volume.\nIncreasing it will increase the precision of the mesh, but will take longer to export and add more vertices."));
}

} // namespace Lab