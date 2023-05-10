// Copyright 2023 saito
#include <chrono>
#include <iostream>
#include <thread>

#include "picrawler.hh"


Picrawler crawler = Picrawler();

int move() {
    while (true) {
        crawler.do_action();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}