#include <assert.h>
#include "mmstack.h"

int main(void) {
	MMStack mms = create_MMStack();
	assert(mms_length(mms) == 0);
	mms_push(mms, 10);
	mms_push(mms, 5);
	mms_push(mms, 20);
	assert(mms_length(mms) == 3);
	assert(mms_max(mms) == 20);
	assert(mms_min(mms) == 5);
	assert(mms_pop(mms) == 20);
	assert(mms_length(mms) == 2);
	assert(mms_max(mms) == 10);
	destroy_MMStack(mms);
}