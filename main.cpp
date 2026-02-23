#include "WxTimerFrame.hpp"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#  include <wx/wx.h>
#endif

namespace
{
class Application : public wxApp
{
  public:
    auto OnInit() -> bool
    {
        wxInitAllImageHandlers();
        //NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
        auto* const ptr_frame = new WxTimerFrame(nullptr);
        ptr_frame->Show(true);
        return true;
    }
};
}    // namespace

wxIMPLEMENT_APP(Application);
