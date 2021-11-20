//
// Created by 李汇川 on 2021/11/19.
//

#include "Video.h"

int main() {
  VideoFactory vf;
  Video *video = vf.getVideo(VideoType(3));
  if (video == NULL) {
    cout << "error" << endl;
  }
  video->produce();

}