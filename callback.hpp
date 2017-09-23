////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef FIRMATA_CALLBACK_HPP
#define FIRMATA_CALLBACK_HPP

////////////////////////////////////////////////////////////////////////////////
#include <functional>
#include <map>

////////////////////////////////////////////////////////////////////////////////
namespace firmata
{

////////////////////////////////////////////////////////////////////////////////
template<typename Fn>
using callback = std::function<Fn>;

////////////////////////////////////////////////////////////////////////////////
template<typename Fn>
struct callback_chain
{
    ////////////////////
    int add(Fn fn) { map_.emplace(id_, std::move(fn)); return id_++; }
    void remove(int id) { map_.erase(id); }

    template<typename... Args>
    void operator()(Args&&... args)
    {
        for(auto const& fn : map_) fn.second(std::forward<Args>(args)...);
    }

private:
    ////////////////////
    std::map<int, Fn> map_;
    int id_ = 0;
};

////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////
#endif
