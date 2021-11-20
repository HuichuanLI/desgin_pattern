 //
// Created by 李汇川 on 2021/11/19.
//

#include "Video.h"

int main() {
  JavaVideoFactory vf;
  Video *video = vf.getVideo();
  if (video == NULL) {
    cout << "error" << endl;
  }
  video->produce();

}