/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm8974.h"

void init_target_properties()
{
    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = property_get("ro.bootloader");

    if (bootloader.find("G900K") == 0) {
        /* kltektt - KT Corp (formerly Korea Telecom) */
        property_override("ro.build.fingerprint", "samsung/kltektt/kltektt:6.0.1/MMB29M/G900KKTU1CPL5:user/release-keys");
        property_override("ro.build.description", "kltektt-user 6.0.1 MMB29M G900KKTU1CPL5 release-keys");
        property_override("ro.product.model", "SM-G900K");
        property_override("ro.product.device", "kltektt");
    } else if (bootloader.find("G900L") == 0) {
        /* kltelgt - LG Uplus */
        property_override("ro.build.fingerprint", "samsung/kltelgt/kltelgt:6.0.1/MMB29M/G900LKLU1CPL5:user/release-keys");
        property_override("ro.build.description", "kltelgt-user 6.0.1 MMB29M G900LKLU1CPL5 release-keys");
        property_override("ro.product.model", "SM-G900L");
        property_override("ro.product.device", "kltelgt");
    } else if (bootloader.find("G900S") == 0) {
        /* klteskt - SK Telecom */
        property_override("ro.build.fingerprint", "samsung/klteskt/klteskt:6.0.1/MMB29M/G900SKSU1CPL5:user/release-keys");
        property_override("ro.build.description", "klteskt-user 6.0.1 MMB29M G900SKSU1CPL5 release-keys");
        property_override("ro.product.model", "SM-G900S");
        property_override("ro.product.device", "klteskt");
    }

    std::string device = property_get("ro.product.device");
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader.c_str(), device.c_str());
}
