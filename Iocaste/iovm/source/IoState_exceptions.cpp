
//--metadoc State copyright Steve Dekorte 2002
//--metadoc State license BSD revised

#include "IoState.h"
#include "IoObject.h"
#include "IoCoroutine.h"
#include "IoSeq.h"

#include "Iocaste/CShims/Exception.h"

void IoState_fatalError_(IoState *self, const char *error)
{
	fputs(error, stderr);
	fputs("\n", stderr);
	exit(-1);
}

void IoState_error_(IoState *self, IoMessage *m, const char *format, ...)
{
	IoSymbol *description;

	va_list ap;
	va_start(ap, format);
	description = IoState_symbolWithUArray_copy_(self, UArray_newWithVargs_(format, ap), 0);
	va_end(ap);

	/*
	fputs("\nIoState_error_: ", stderr);
	fputs(CSTRING(description), stderr);
	fputs("\n\n", stderr);
	*/
	while(Collector_isPaused(self->collector))
	{
		Collector_popPause(self->collector);
	}

	/* replaced with Iocaste_raiseError
	{
		IoCoroutine *coroutine = IoState_currentCoroutine(self);
		IoCoroutine_raiseError(coroutine, description, m);
	}
	*/

    IoCoroutine *coroutine = IoState_currentCoroutine(self);
    Iocaste_raiseError(coroutine, CSTRING(description), m);
}
