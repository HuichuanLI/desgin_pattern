//
// Created by 李汇川 on 2021/11/19.
//

#include "Video.h"

int main() {
  JavaCourseFactory vf;
  Video *video = vf.getVideo();
  Article *article = vf.getArticle();

  video->produce();
  article->produce();
}