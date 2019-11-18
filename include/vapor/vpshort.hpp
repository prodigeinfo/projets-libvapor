/*
 * Copyright (c) 2019 Prodige Informatique, s.a.  All rights reserved.
 * Copyright (c) 2019 Stephane Russell.  All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Prodige Informatique nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific, prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef VPSHORT_HPP
#define VPSHORT_HPP

#include "vpbasictype.hpp"
#include <boost/lexical_cast.hpp>

namespace vapor
{

typedef int16_t vpshort_t;
typedef vpbasictype<vpshort_t> vpshortbase_t;

class vpshort: public vpshortbase_t, public vptype
{
public:
    vpshort() {}
    vpshort(vpshort_t x) : vpshortbase_t(x) {}

    virtual vparchive_t serialize() const throw(std::runtime_error)
    {
        std::string content = boost::lexical_cast<std::string>(_v);
        return std::string(TYPE) + ';' + boost::lexical_cast<std::string>(content.length()) + ';' + content;
    }

    virtual void deserialize(const char *s) throw(std::runtime_error, std::out_of_range, std::invalid_argument)
    {
        std::pair<std::string, std::string> rs = vptype::split(s);
        if (rs.first != TYPE) throw std::invalid_argument("bad format");
        _v = boost::lexical_cast<vpshort_t>(rs.second);
    }

    VPTYPE_BASIC_TYPE_GET_DECL(vpshort_t, vpshort)
    VPTYPE_BASIC_TYPE_READ_DECL(vpshort_t, vpshort)
    VPTYPE_BASIC_TYPE_READ_TO_OTHER_TYPE_DECL(short, short, vpshort)
    VPTYPE_BASIC_TYPE_READ_TO_OTHER_TYPE_DECL(int, int, vpshort)
    VPTYPE_BASIC_TYPE_READ_TO_OTHER_TYPE_DECL(long, long, vpshort)
    VPTYPE_BASIC_TYPE_READ_TO_OTHER_TYPE_DECL(longlong, long long, vpshort)
    VPTYPE_CLASS_DECL(short, vpshort)
};

} // End namespace vapor.

#endif // VPINT_HPP
