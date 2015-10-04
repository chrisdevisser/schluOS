#pragma once

namespace std {

//Used in the detection idiom as a failure type.
struct nonesuch {
    nonesuch() = delete;
    nonesuch(const nonesuch&) = delete;
    ~nonesuch() = delete;
    void operator=(const nonesuch&) = delete;
};

}
