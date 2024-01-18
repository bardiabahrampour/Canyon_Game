#pragma once

template <typename T> constexpr auto FUNC_FINISHED(T func_name) {
  return func_name + " -> Finished\n";
}
template <typename T> constexpr auto FUNC_INIT_PENDING(T func_name) {
  return func_name + " -> Initialization Pending\n";
}
template <typename T> constexpr auto FUNC_INIT_DONE(T func_name) {
  return func_name + " -> Initialization Done\n";
}
template <typename T> constexpr auto FUNC_BEGAN(T func_name) {
  return func_name + " -> Began\n";
}
