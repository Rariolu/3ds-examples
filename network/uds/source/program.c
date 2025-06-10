#ifndef PROGRAM_C
#define PROGRAM_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <errno.h>
#include <stdarg.h>
#include <unistd.h>

#include <3ds.h>
#include "./udsutil.c"

int main()
{
	Result ret=0;

	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	printf("libctru UDS local-WLAN demo.\n");

	ret = udsInit(0x3000, NULL);//The sharedmem size only needs to be slightly larger than the total recv_buffer_size for all binds, with page-alignment.
	if(R_FAILED(ret))
	{
		printf("udsInit failed: 0x%08x.\n", (unsigned int)ret);
	}
	else
	{
		uds_testt();
		udsExit();
	}

	printf("Press START to exit.\n");

	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		hidScanInput();

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();
	}

	gfxExit();
	return 0;
}

#endif