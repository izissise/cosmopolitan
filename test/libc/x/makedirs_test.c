/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2022 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/mem/mem.h"
#include "libc/mem/gc.internal.h"
#include "libc/testlib/testlib.h"
#include "libc/thread/spawn.h"
#include "libc/thread/thread.h"
#include "libc/x/x.h"

#define DIR                                                                    \
  "a/b/c/d/e/f/g/h/i/j/k/l/m/n/o/p/q/r/s/t/u/v/w/x/y/z/A/B/C/D/E/F/G/H/I/J/K/" \
  "L/M/N/O/P/Q/R/S/T/U/V/W/X/Y/Z"

pthread_barrier_t barrier;
char testlib_enable_tmp_setup_teardown;

int Worker(void *arg, int tid) {
  pthread_barrier_wait(&barrier);
  ASSERT_EQ(0, makedirs(DIR, 0755));
  return 0;
}

TEST(makedirs, test) {
  int i, n = 8;
  struct spawn *t = gc(malloc(sizeof(struct spawn) * n));
  ASSERT_EQ(0, pthread_barrier_init(&barrier, 0, n));
  for (i = 0; i < n; ++i) ASSERT_SYS(0, 0, _spawn(Worker, 0, t + i));
  for (i = 0; i < n; ++i) EXPECT_SYS(0, 0, _join(t + i));
  ASSERT_EQ(0, pthread_barrier_destroy(&barrier));
}
