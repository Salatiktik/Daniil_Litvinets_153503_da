#ifndef MVECTOR_GLOBAL_H
#define MVECTOR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MVECTOR_LIBRARY)
#  define MVECTOR_EXPORT Q_DECL_EXPORT
#else
#  define MVECTOR_EXPORT Q_DECL_IMPORT
#endif

#endif // MVECTOR_GLOBAL_H
