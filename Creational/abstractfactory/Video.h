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


class Article {

 public:
  Article() {};
  ~Article() {};

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
  virtual Video *getVideo() = 0;
};
class JavaVideoFactory : public VideoFactory {
 public:
  virtual Video *getVideo() {
    return new JavaVideo();
  }
};

class PythonVideoFactory : public VideoFactory {
 public:
  virtual Video *getVideo() {
    return new PythonVideo();
  }
};
#endif //DESGIN_PATTERN_BEHAVIORAL_SIMPLEFACTORY_VIDEO_H_
