/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2020 Justine Alexandra Roberts Tunney                              │
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
#include "libc/errno.h"
#include "libc/mem/alg.h"
#include "libc/mem/gc.h"
#include "libc/testlib/testlib.h"

TEST(_replacestr, demo) {
  EXPECT_STREQ("hello friends",
               _gc(_replacestr("hello world", "world", "friends")));
  EXPECT_STREQ("bbbbbbbb", _gc(_replacestr("aaaa", "a", "bb")));
}

TEST(_replacestr, emptyString) {
  EXPECT_STREQ("", _gc(_replacestr("", "x", "y")));
}

TEST(_replacestr, emptyNeedle) {
  EXPECT_EQ(NULL, _gc(_replacestr("a", "", "a")));
  EXPECT_EQ(EINVAL, errno);
}

TEST(_replacestr, needleInReplacement_doesntExplode) {
  EXPECT_STREQ("xxxxxxx", _gc(_replacestr("x", "x", "xxxxxxx")));
}
