#pragma once
#include <string>
#include <vector>

class FileExtensionList
{
  private:
    std::vector<std::string> m_list;

  public:
    FileExtensionList(std::initializer_list<std::string> list);

    auto begin(this auto&& self) {return self.m_list.begin();}
    auto end(this auto&& self) {return self.m_list.end();}

    [[nodiscard]]
    auto size() const;

    auto operator[] (this auto&& self, std::size_t idx) -> decltype(auto);

    [[nodiscard]]
    auto getWildcardForFileDialogue(bool includeAllFiles = true, bool includeCombined = true) const -> std::string;
};
