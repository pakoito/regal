

/*
  file generated by scripts/initLayers.py, edit at your peril
*/
#include "pch.h" /* For MS precompiled header support */

#include "RegalUtil.h"

#if ! REGAL_SYS_WGL
#include <dlfcn.h>
#else
#error "Implement me!"
#endif

REGAL_GLOBAL_BEGIN

#include <string>
using namespace std;

#include "RegalLog.h"
#include "RegalContext.h"
#include "RegalDispatch.h"

REGAL_GLOBAL_END

REGAL_NAMESPACE_BEGIN

typedef Layer *(*Constructor)( RegalContext * ctx );

Constructor GetConstructor( const char * constructorName ) {
  Constructor c = reinterpret_cast<Constructor>( dlsym( NULL, constructorName ) );
  return c;
}

void InitLayers( RegalContext * ctx ) {
  Constructor constr = NULL;
  Layer * layer = NULL;
  constr = GetConstructor( "createFilter" );
  if( constr ) {
    layer = constr( ctx );
    bool success = layer->Initialize( "" );
    if( success ) {
      ctx->layer.push_back( layer );
    }
  }

}

REGAL_NAMESPACE_END

