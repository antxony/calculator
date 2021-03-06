/**
 * calculate results
 */
#include <calculator.hh>

using namespace Calculator;

void CalculatorWindow::operate()
{
    double screenValue;
    char output[DISPLAY_BURFFER_SIZE], preoutput[DISPLAY_BURFFER_SIZE];
    int i;
    this->decimalPoint = false;
    //get display as double
    this->display->GetValue().ToDouble(&screenValue);
    //asm lib
    switch (this->oper)
    {
    case OP_ADD:
        this->stored = add(this->stored, screenValue);
        break;
    case OP_SUB:
        this->stored = sub(this->stored, screenValue);
        break;
    case OP_TIMES:
        this->stored = mul(this->stored, screenValue);
        break;
    case OP_DIV:
        this->stored = div(this->stored, screenValue);
        break;
    case OP_SQ_ROOT:
        this->stored = sqroot(screenValue);
        break;
    case OP_SQ_EXP:
        this->stored = sqexp(screenValue);
        break;     
    case OP_LOG:
        this->stored = log(screenValue);
        break;
    case OP_ANTILOG:
        this->stored = antilog(screenValue);
        break;
    case OP_SIN:
        if(this->degrees) {
            screenValue = degreesToRadians(screenValue);
        }
        this->stored = sin(screenValue);
        break;
    case OP_COS:
        if(this->degrees) {
            screenValue = degreesToRadians(screenValue);
        }
        this->stored = cos(screenValue);
        break;
    case OP_TAN:
        if(this->degrees) {
            screenValue = degreesToRadians(screenValue);
        }
        this->stored = tan(screenValue);
        break;
    case OP_ARCSIN:
        this->stored = arcsin(screenValue);
        if(this->degrees) {
            this->stored = radiansToDegrees(this->stored);
        }
        break;
    case OP_ARCTAN:
        this->stored = arctan(screenValue);
        if(this->degrees) {
            this->stored = radiansToDegrees(this->stored);
        }
        break;
    case OP_ARCCOS:
        this->stored = arccos(screenValue);
        if(this->degrees) {
            this->stored = radiansToDegrees(this->stored);
        }
        break;
    default:
        this->stored = screenValue;
        break;
    }
    //stringify the result
    strncpy(preoutput, wxString::Format("%f", this->stored).mb_str().data(), DISPLAY_BURFFER_SIZE);
    //remove trailing right zeros
    for (i = DISPLAY_BURFFER_SIZE - 1; i >= 0; i--)
    {
        this->decimalPoint = (preoutput[i] != '0' && preoutput[i] != 0 && preoutput[i] != '.');
        if (preoutput[i] == '.' || this->decimalPoint)
        {
            break;
        }
    }
    //if there is a decimal value we add one character, else we don't take the decimal point
    if (this->decimalPoint)
    {
        i++;
    }
    //clear output
    strncpy(output, preoutput, i);
    //end of string
    output[i] = 0;
    //set negative if needed
    this->negative = (output[0] == '-');
    //update screen
    this->display->ChangeValue(output);
}