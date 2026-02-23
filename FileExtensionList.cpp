#include "FileExtensionList.hpp"
#include <format>
#include <ranges>

FileExtensionList::FileExtensionList(std::initializer_list<std::string> list) : m_list {std::vector<std::string>(list)}
{
    // empty
}
[[nodiscard]]
auto FileExtensionList::size() const
{
    return m_list.size();
}
[[nodiscard]]
auto FileExtensionList::getWildcardForFileDialogue(bool includeAllFiles, bool includeCombined) const -> std::string
{
    // generate wildcard string from ALLOWED_EXTENSIONS.
    // Wildcard format: "Description 1 (*.ext1, *.ext2)|*.ext1;*.ext2|Description 2 (*.ext3)|*.ext3"
    // Where Descriptions and extensions are separated by '|'.
    // Individial extensions are separated by ; and are actually globs.
    // And different categories are also separated by '|'.
    std::string wildcard;
    if (includeCombined && m_list.size() > 1)
    {
        wildcard += "Allowed Files (";
        wildcard +=
          std::ranges::transform_view(m_list, [](const std::string& extension) { return std::format("*.{}", extension); })

          | std::views::join_with(std::string(", "))
          | std::ranges::to<std::string>();
        wildcard += ")|";
        wildcard +=
          std::ranges::transform_view(m_list, [](const std::string& extension) { return std::format("*.{}", extension); })
          | std::views::join_with(std::string(";"))
          | std::ranges::to<std::string>();
        wildcard += "|";
    }
    // add them individually
    wildcard += std::ranges::transform_view(
                  m_list, [](const std::string& extension) { return std::format("{0} Files (*.{0})|*.{0}", extension); }
                )
                | std::views::join_with(std::string("|"))
                | std::ranges::to<std::string>();

    if (includeAllFiles)
    {
        wildcard += "|All Files (*.*)|*.*";
    }
    return wildcard;
}

auto FileExtensionList::operator[] (this auto&& self, std::size_t idx) -> decltype(auto)
{
    return std::forward_like<decltype(self)>(self.m_list[idx]);
}

