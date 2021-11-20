//
// Created by 李汇川 on 2021/11/19.
//

#ifndef DESGIN_PATTERN_BEHAVIORAL_SIMPLEFACTORY_VIDEO_H_
#define DESGIN_PATTERN_BEHAVIORAL_SIMPLEFACTORY_VIDEO_H_
#include <iostream>
using namespace std;
enum VideoType { JV, PV };
class Video {

 public:
  Video() {};
  ~Video() {};

  virtual void produce() = 0;
};

class JavaVideo : public Video {
 public:
  void produce() {
    cout << "录制Java课程视频" << endl;
  }
};

class PythonVideo : public Video {
 public:
  void produce() {
    cout << "录制Python课程视频" << endl;
  }
};
class VideoFactory {
 public:
  Video *getVideo(VideoType type) {
    switch (type) {
      case JV:return new JavaVideo();
        break;
      case PV :return new PythonVideo();
        break;
      default: return NULL;
        break;

    }

  }
};
#endif //DESGIN_PATTERN_BEHAVIORAL_SIMPLEFACTORY_VIDEO_H_
