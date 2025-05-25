/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2025, Roger Ortiz <me@r0rt1z2.com>
 */
#include <board.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>

void init_board_funcs(void *board)
{
	/*
	 * Parsing the struct directly without restructing is
	 * broken as of Sep 29 2024
	 */
	struct {
		const char *name;
		int ops[BOARD_OP_EXIT];
	} *board_restruct = board;

	board_restruct->name = "Honor View 10";
}

// Early initialization
int board_init(void)
{
	return 0;
}

// Late initialization
int board_late_init(void)
{
	return 0;
}

int board_driver_setup(void)
{
	struct {
		int width;
		int height;
		int stride;
		void *address;
	} simplefb_data = {
		.width = 1080,
		.height = 2160,
		.stride = 4,
		.address = (void *)0x10600000
	};

	REGISTER_DRIVER("simplefb", simplefb_probe, &simplefb_data);
	return 0;
}