#ifndef CALCULATOR_HH
#define CALCULATOR_HH
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/grid.h>
#include <wx/font.h>
#include <cstring>
#include <calcmath/calcmath.hh>
namespace Calculator
{
    const wxString DISPLAY_ZERO = "0";
    const wxString DISPLAY_DECIMAL = ".";
    const wxString DISPLAY_DEG = "deg";
    const wxString DISPLAY_RAD = "rad";
    const unsigned int DISPLAY_FONT_SIZE = 20;
    const unsigned int DISPLAY_BURFFER_SIZE = 50;
    const unsigned int DISPLAY_ID = 50;
    typedef enum
    {
        OP_NONE,
        OP_ADD,
        OP_SUB,
        OP_TIMES,
        OP_DIV,
        OP_SQ_ROOT,
        OP_SQ_EXP,
        OP_LOG,
        OP_ANTILOG,
        OP_SIN,
        OP_COS,
        OP_TAN,
        OP_ARCSIN,
        OP_ARCCOS,
        OP_ARCTAN
    } OPER;
    enum OPTIONS
    {
        CALC_0,
        CALC_1,
        CALC_2,
        CALC_3,
        CALC_4,
        CALC_5,
        CALC_6,
        CALC_7,
        CALC_8,
        CALC_9,
        CALC_CLS,
        CALC_BACK,
        CALC_EQUAL,
        CALC_PLUS,
        CALC_MINUS,
        CALC_TIMES,
        CALC_DIV,
        CALC_POINT,
        CALC_NEGATIVE,
        CALC_SQUARE_ROOT,
        CALC_SQUARE_EXP,
        CALC_LOG,
        CALC_ANTILOG,
        CALC_SIN,
        CALC_COS,
        CALC_TAN,
        CALC_DEG_RAD,
        CALC_ARCSIN,
        CALC_ARCCOS,
        CALC_ARCTAN
    };
    const OPTIONS All[] = {
        CALC_0,
        CALC_1,
        CALC_2,
        CALC_3,
        CALC_4,
        CALC_5,
        CALC_6,
        CALC_7,
        CALC_8,
        CALC_9,
        CALC_CLS,
        CALC_BACK,
        CALC_EQUAL,
        CALC_PLUS,
        CALC_MINUS,
        CALC_TIMES,
        CALC_DIV,
        CALC_POINT,
        CALC_NEGATIVE,
        CALC_SQUARE_ROOT,
        CALC_SQUARE_EXP,
        CALC_LOG,
        CALC_ANTILOG,
        CALC_SIN,
        CALC_COS,
        CALC_TAN,
        CALC_DEG_RAD,
        CALC_ARCSIN,
        CALC_ARCCOS,
        CALC_ARCTAN
        };

    class CalculatorWindow : public wxFrame
    {
    public:
        CalculatorWindow(wxSize);

    private:
        void build();
        void onExit(wxCommandEvent &);
        void onClick(wxCommandEvent &);
        void clearScreen();
        bool isDisplayZero();
        bool isDisplayOneDigit();
        void operate();
        wxBoxSizer *box;
        wxGridSizer *grid;
        wxTextCtrl *display;
        bool decimalPoint;
        bool negative;
        bool newValue;
        bool degrees;
        wxStaticText *degRad;
        OPER oper;
        double stored;
        wxSize size;
    };

} // namespace Calculator
#endif