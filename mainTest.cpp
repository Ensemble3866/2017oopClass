#include <gtest/gtest.h>
#include "utAtom.h"
//#include "utExp.h"
//#include "utIterator.h"
#include "utList.h"
#include "utParser.h"
#include "utScanner.h"
#include "utStruct.h"
#include "utVariable.h"
#include "expression.h"
#include "exception.h"

int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}
