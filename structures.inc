struc CONSOLE_SCREEN_BUFFER_INFO{
      .dwSize COORD             ;
      .dwCursorPosition COORD
      .wAttributes dw ?
      .srWindow SMALL_RECT
      .dwMaximumWindowSize COORD
}
struc SMALL_RECT{
      .left    dw ?
      .top     dw ?
      .right   dw ?
      .bottom  dw ?
}
struc COORD {
      .x dw ?
      .y dw ?
}