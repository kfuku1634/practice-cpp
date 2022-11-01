cc_test(
  name = "priority_queue_test",
  size = "small",
  srcs = ["priority_queue_test.cc"],
  deps = ["@com_google_googletest//:gtest_main", "priority_queue"],
)

cc_library(
  name = "priority_queue",
  srcs = ["priority_queue.cc"],
  hdrs = ["priority_queue.h"],
  deps = ["//vector:vector"]
)

