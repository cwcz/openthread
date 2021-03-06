/*
 *  Copyright (c) 2016, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *   This file includes functions for debugging.
 */

#ifndef LOGGING_HPP_
#define LOGGING_HPP_

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include <openthread-core-config.h>
#include "openthread/platform/logging.h"

#ifdef WINDOWS_LOGGING
#ifdef _KERNEL_MODE
#include <wdm.h>
#endif
#include "openthread/platform/logging-windows.h"
#ifdef WPP_NAME
#include WPP_NAME
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WINDOWS_LOGGING
#define otLogFuncEntry()
#define otLogFuncEntryMsg(aFormat, ...)
#define otLogFuncExit()
#define otLogFuncExitMsg(aFormat, ...)
#define otLogFuncExitErr(error)
#endif

/**
 * @def otLogCrit
 *
 * Logging at log level critical.
 *
 * @param[in]  aRegion  The log region.
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_LEVEL >= OPENTHREAD_LOG_LEVEL_CRIT
#define otLogCrit(aRegion, aFormat, ...)  _otLogFormatter(kLogLevelCrit, aRegion, aFormat, ## __VA_ARGS__)
#else
#define otLogCrit(aRegion, aFormat, ...)
#endif

/**
 * @def otLogWarn
 *
 * Logging at log level warning.
 *
 * @param[in]  aRegion  The log region.
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_LEVEL >= OPENTHREAD_LOG_LEVEL_WARN
#define otLogWarn(aRegion, aFormat, ...)  _otLogFormatter(kLogLevelWarn, aRegion, aFormat, ## __VA_ARGS__)
#else
#define otLogWarn(aRegion, aFormat, ...)
#endif

/**
 * @def otLogInfo
 *
 * Logging at log level info.
 *
 * @param[in]  aRegion  The log region.
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_LEVEL >= OPENTHREAD_LOG_LEVEL_INFO
#define otLogInfo(aRegion, aFormat, ...)  _otLogFormatter(kLogLevelInfo, aRegion, aFormat, ## __VA_ARGS__)
#else
#define otLogInfo(aRegion, aFormat, ...)
#endif

/**
 * @def otLogDebg
 *
 * Logging at log level debug.
 *
 * @param[in]  aRegion  The log region.
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_LEVEL >= OPENTHREAD_LOG_LEVEL_DEBG
#define otLogDebg(aRegion, aFormat, ...)  _otLogFormatter(kLogLevelDebg, aRegion, aFormat, ## __VA_ARGS__)
#else
#define otLogDebg(aRegion, aFormat, ...)
#endif

#ifndef WINDOWS_LOGGING

/**
 * @def otLogCritApi
 *
 * This method generates a log with level critical for the API region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogWarnApi
 *
 * This method generates a log with level warning for the API region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogInfoApi
 *
 * This method generates a log with level info for the API region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogDebgApi
 *
 * This method generates a log with level debug for the API region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_API == 1
#define otLogCritApi(aFormat, ...) otLogCrit(kLogRegionApi, aFormat, ## __VA_ARGS__)
#define otLogWarnApi(aFormat, ...) otLogWarn(kLogRegionApi, aFormat, ## __VA_ARGS__)
#define otLogInfoApi(aFormat, ...) otLogInfo(kLogRegionApi, aFormat, ## __VA_ARGS__)
#define otLogDebgApi(aFormat, ...) otLogDebg(kLogRegionApi, aFormat, ## __VA_ARGS__)
#else
#define otLogCritApi(aFormat, ...)
#define otLogWarnApi(aFormat, ...)
#define otLogInfoApi(aFormat, ...)
#define otLogDebgApi(aFormat, ...)
#endif

/**
 * @def otLogCritMeshCoP
 *
 * This method generates a log with level critical for the MLE region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogWarnMeshCoP
 *
 * This method generates a log with level warning for the MLE region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogInfoMeshCoP
 *
 * This method generates a log with level info for the MLE region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogDebgMeshCoP
 *
 * This method generates a log with level debug for the MLE region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_MLE == 1
#define otLogCritMeshCoP(aFormat, ...) otLogCrit(kLogRegionMeshCoP, aFormat, ## __VA_ARGS__)
#define otLogWarnMeshCoP(aFormat, ...) otLogWarn(kLogRegionMeshCoP, aFormat, ## __VA_ARGS__)
#define otLogInfoMeshCoP(aFormat, ...) otLogInfo(kLogRegionMeshCoP, aFormat, ## __VA_ARGS__)
#define otLogDebgMeshCoP(aFormat, ...) otLogDebg(kLogRegionMeshCoP, aFormat, ## __VA_ARGS__)
#else
#define otLogCritMeshCoP(aFormat, ...)
#define otLogWarnMeshCoP(aFormat, ...)
#define otLogInfoMeshCoP(aFormat, ...)
#define otLogDebgMeshCoP(aFormat, ...)
#endif

#define otLogCritMbedTls(aFormat, ...) otLogCritMeshCoP(aFormat, ## __VA_ARGS__)
#define otLogWarnMbedTls(aFormat, ...) otLogWarnMeshCoP(aFormat, ## __VA_ARGS__)
#define otLogInfoMbedTls(aFormat, ...) otLogInfoMeshCoP(aFormat, ## __VA_ARGS__)
#define otLogDebgMbedTls(aFormat, ...) otLogDebgMeshCoP(aFormat, ## __VA_ARGS__)

/**
 * @def otLogCritMle
 *
 * This method generates a log with level critical for the MLE region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogWarnMle
 *
 * This method generates a log with level warning for the MLE region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogInfoMle
 *
 * This method generates a log with level info for the MLE region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogDebgMle
 *
 * This method generates a log with level debug for the MLE region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_MLE == 1
#define otLogCritMle(aFormat, ...) otLogCrit(kLogRegionMle, aFormat, ## __VA_ARGS__)
#define otLogWarnMle(aFormat, ...) otLogWarn(kLogRegionMle, aFormat, ## __VA_ARGS__)
#define otLogWarnMleErr(aError, aFormat, ...) otLogWarn(kLogRegionMac, "Error %s: " aFormat, otThreadErrorToString(aError), ## __VA_ARGS__)
#define otLogInfoMle(aFormat, ...) otLogInfo(kLogRegionMle, aFormat, ## __VA_ARGS__)
#define otLogDebgMle(aFormat, ...) otLogDebg(kLogRegionMle, aFormat, ## __VA_ARGS__)
#else
#define otLogCritMle(aFormat, ...)
#define otLogWarnMle(aFormat, ...)
#define otLogWarnMleErr(aError, aFormat, ...)
#define otLogInfoMle(aFormat, ...)
#define otLogDebgMle(aFormat, ...)
#endif

/**
 * @def otLogCritArp
 *
 * This method generates a log with level critical for the EID-to-RLOC mapping region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogWarnArp
 *
 * This method generates a log with level warning for the EID-to-RLOC mapping region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogInfoArp
 *
 * This method generates a log with level info for the EID-to-RLOC mapping region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogDebgArp
 *
 * This method generates a log with level debug for the EID-to-RLOC mapping region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_ARP == 1
#define otLogCritArp(aFormat, ...) otLogCrit(kLogRegionArp, aFormat, ## __VA_ARGS__)
#define otLogWarnArp(aFormat, ...) otLogWarn(kLogRegionArp, aFormat, ## __VA_ARGS__)
#define otLogInfoArp(aFormat, ...) otLogInfo(kLogRegionArp, aFormat, ## __VA_ARGS__)
#define otLogDebgArp(aFormat, ...) otLogDebg(kLogRegionArp, aFormat, ## __VA_ARGS__)
#else
#define otLogCritArp(aFormat, ...)
#define otLogWarnArp(aFormat, ...)
#define otLogInfoArp(aFormat, ...)
#define otLogDebgArp(aFormat, ...)
#endif

/**
 * @def otLogCritNetData
 *
 * This method generates a log with level critical for the Network Data region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogWarnNetData
 *
 * This method generates a log with level warning for the Network Data region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogInfoNetData
 *
 * This method generates a log with level info for the Network Data region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogDebgNetData
 *
 * This method generates a log with level debug for the Network Data region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_NETDATA == 1
#define otLogCritNetData(aFormat, ...) otLogCrit(kLogRegionNetData, aFormat, ## __VA_ARGS__)
#define otLogWarnNetData(aFormat, ...) otLogWarn(kLogRegionNetData, aFormat, ## __VA_ARGS__)
#define otLogInfoNetData(aFormat, ...) otLogInfo(kLogRegionNetData, aFormat, ## __VA_ARGS__)
#define otLogDebgNetData(aFormat, ...) otLogDebg(kLogRegionNetData, aFormat, ## __VA_ARGS__)
#else
#define otLogCritNetData(aFormat, ...)
#define otLogWarnNetData(aFormat, ...)
#define otLogInfoNetData(aFormat, ...)
#define otLogDebgNetData(aFormat, ...)
#endif

/**
 * @def otLogCritIcmp
 *
 * This method generates a log with level critical for the ICMPv6 region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogWarnIcmp
 *
 * This method generates a log with level warning for the ICMPv6 region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogInfoIcmp
 *
 * This method generates a log with level info for the ICMPv6 region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogDebgIcmp
 *
 * This method generates a log with level debug for the ICMPv6 region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_ICMP == 1
#define otLogCritIcmp(aFormat, ...) otLogCrit(kLogRegionIcmp, aFormat, ## __VA_ARGS__)
#define otLogWarnIcmp(aFormat, ...) otLogWarn(kLogRegionIcmp, aFormat, ## __VA_ARGS__)
#define otLogInfoIcmp(aFormat, ...) otLogInfo(kLogRegionIcmp, aFormat, ## __VA_ARGS__)
#define otLogDebgIcmp(aFormat, ...) otLogDebg(kLogRegionIcmp, aFormat, ## __VA_ARGS__)
#else
#define otLogCritIcmp(aFormat, ...)
#define otLogWarnIcmp(aFormat, ...)
#define otLogInfoIcmp(aFormat, ...)
#define otLogDebgIcmp(aFormat, ...)
#endif

/**
 * @def otLogCritIp6
 *
 * This method generates a log with level critical for the IPv6 region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogWarnIp6
 *
 * This method generates a log with level warning for the IPv6 region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogInfoIp6
 *
 * This method generates a log with level info for the IPv6 region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogDebgIp6
 *
 * This method generates a log with level debug for the IPv6 region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_IP6 == 1
#define otLogCritIp6(aFormat, ...) otLogCrit(kLogRegionIp6, aFormat, ## __VA_ARGS__)
#define otLogWarnIp6(aFormat, ...) otLogWarn(kLogRegionIp6, aFormat, ## __VA_ARGS__)
#define otLogInfoIp6(aFormat, ...) otLogInfo(kLogRegionIp6, aFormat, ## __VA_ARGS__)
#define otLogDebgIp6(aFormat, ...) otLogDebg(kLogRegionIp6, aFormat, ## __VA_ARGS__)
#else
#define otLogCritIp6(aFormat, ...)
#define otLogWarnIp6(aFormat, ...)
#define otLogInfoIp6(aFormat, ...)
#define otLogDebgIp6(aFormat, ...)
#endif

/**
 * @def otLogCritMac
 *
 * This method generates a log with level critical for the MAC region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogWarnMac
 *
 * This method generates a log with level warning for the MAC region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogInfoMac
 *
 * This method generates a log with level info for the MAC region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogDebgMac
 *
 * This method generates a log with level debug for the MAC region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_MAC == 1
#define otLogCritMac(aFormat, ...) otLogCrit(kLogRegionMac, aFormat, ## __VA_ARGS__)
#define otLogWarnMac(aFormat, ...) otLogWarn(kLogRegionMac, aFormat, ## __VA_ARGS__)
#define otLogInfoMac(aFormat, ...) otLogInfo(kLogRegionMac, aFormat, ## __VA_ARGS__)
#define otLogDebgMac(aFormat, ...) otLogDebg(kLogRegionMac, aFormat, ## __VA_ARGS__)
#define otLogDebgMacErr(aError, aFormat, ...) otLogWarn(kLogRegionMac, "Error %s: " aFormat, otThreadErrorToString(aError), ## __VA_ARGS__)
#else
#define otLogCritMac(aFormat, ...)
#define otLogWarnMac(aFormat, ...)
#define otLogInfoMac(aFormat, ...)
#define otLogDebgMac(aFormat, ...)
#define otLogDebgMacErr(aError, aFormat, ...)
#endif

/**
 * @def otLogCritMem
 *
 * This method generates a log with level critical for the memory region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogWarnMem
 *
 * This method generates a log with level warning for the memory region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogInfoMem
 *
 * This method generates a log with level info for the memory region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogDebgMem
 *
 * This method generates a log with level debug for the memory region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_MEM == 1
#define otLogCritMem(aFormat, ...) otLogCrit(kLogRegionMem, aFormat, ## __VA_ARGS__)
#define otLogWarnMem(aFormat, ...) otLogWarn(kLogRegionMem, aFormat, ## __VA_ARGS__)
#define otLogInfoMem(aFormat, ...) otLogInfo(kLogRegionMem, aFormat, ## __VA_ARGS__)
#define otLogDebgMem(aFormat, ...) otLogDebg(kLogRegionMem, aFormat, ## __VA_ARGS__)
#else
#define otLogCritMem(aFormat, ...)
#define otLogWarnMem(aFormat, ...)
#define otLogInfoMem(aFormat, ...)
#define otLogDebgMem(aFormat, ...)
#endif

/**
 * @def otLogCritNetDiag
 *
 * This method generates a log with level critical for the NETDIAG region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogWarnNetDiag
 *
 * This method generates a log with level warning for the NETDIAG region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogInfoNetDiag
 *
 * This method generates a log with level info for the NETDIAG region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */

/**
 * @def otLogDebgNetDiag
 *
 * This method generates a log with level debug for the NETDIAG region.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_CONFIG_LOG_NETDIAG == 1
#define otLogCritNetDiag(aFormat, ...) otLogCrit(kLogRegionNetDiag, aFormat, ## __VA_ARGS__)
#define otLogWarnNetDiag(aFormat, ...) otLogWarn(kLogRegionNetDiag, aFormat, ## __VA_ARGS__)
#define otLogInfoNetDiag(aFormat, ...) otLogInfo(kLogRegionNetDiag, aFormat, ## __VA_ARGS__)
#define otLogDebgNetDiag(aFormat, ...) otLogDebg(kLogRegionNetDiag, aFormat, ## __VA_ARGS__)
#else
#define otLogCritNetDiag(aFormat, ...)
#define otLogWarnNetDiag(aFormat, ...)
#define otLogInfoNetDiag(aFormat, ...)
#define otLogDebgNetDiag(aFormat, ...)
#endif

/**
 * @def otLogCert
 *
 * This method generates a log with level none for the certification test.
 *
 * @param[in]  aFormat  A pointer to the format string.
 * @param[in]  ...      Arguments for the format specification.
 *
 */
#if OPENTHREAD_ENABLE_CERT_LOG
#define otLogCertMeshCoP(aFormat, ...) _otLogFormatter(kLogLevelNone, kLogRegionMeshCoP, aFormat, ## __VA_ARGS__)
#else
#define otLogCertMeshCoP(aFormat, ...)
#endif

/**
* @def otLogCritPlat
*
* This method generates a log with level critical for the Platform region.
*
* @param[in]  aFormat  A pointer to the format string.
* @param[in]  ...      Arguments for the format specification.
*
*/

/**
* @def otLogWarnPlat
*
* This method generates a log with level warning for the Platform region.
*
* @param[in]  aFormat  A pointer to the format string.
* @param[in]  ...      Arguments for the format specification.
*
*/

/**
* @def otLogInfoPlat
*
* This method generates a log with level info for the Platform region.
*
* @param[in]  aFormat  A pointer to the format string.
* @param[in]  ...      Arguments for the format specification.
*
*/

/**
* @def otLogDebgPlat
*
* This method generates a log with level debug for the Platform region.
*
* @param[in]  aFormat  A pointer to the format string.
* @param[in]  ...      Arguments for the format specification.
*
*/
#if OPENTHREAD_CONFIG_LOG_PLATFORM == 1
#define otLogCritPlat(aFormat, ...) otLogCrit(kLogRegionPlatform, aFormat, ## __VA_ARGS__)
#define otLogWarnPlat(aFormat, ...) otLogWarn(kLogRegionPlatform, aFormat, ## __VA_ARGS__)
#define otLogInfoPlat(aFormat, ...) otLogInfo(kLogRegionPlatform, aFormat, ## __VA_ARGS__)
#define otLogDebgPlat(aFormat, ...) otLogDebg(kLogRegionPlatform, aFormat, ## __VA_ARGS__)
#else
#define otLogCritPlat(aFormat, ...)
#define otLogWarnPlat(aFormat, ...)
#define otLogInfoPlat(aFormat, ...)
#define otLogDebgPlat(aFormat, ...)
#endif

#endif // WINDOWS_LOGGING

/**
 * @def otDumpCrit
 *
 * This method generates a memory dump with log level critical.
 *
 * @param[in]  aRegion  The log region.
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
#if OPENTHREAD_CONFIG_LOG_LEVEL >= OPENTHREAD_LOG_LEVEL_CRIT
#define otDumpCrit(aRegion, aId, aBuf, aLength)  otDump(kLogLevelCrit, aRegion, aId, aBuf, aLength)
#else
#define otDumpCrit(aRegion, aId, aBuf, aLength)
#endif

/**
 * @def otDumpWarn
 *
 * This method generates a memory dump with log level warning.
 *
 * @param[in]  aRegion  The log region.
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
#if OPENTHREAD_CONFIG_LOG_LEVEL >= OPENTHREAD_LOG_LEVEL_WARN
#define otDumpWarn(aRegion, aId, aBuf, aLength)  otDump(kLogLevelWarn, aRegion, aId, aBuf, aLength)
#else
#define otDumpWarn(aRegion, aId, aBuf, aLength)
#endif

/**
 * @def otDumpInfo
 *
 * This method generates a memory dump with log level info.
 *
 * @param[in]  aRegion  The log region.
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
#if OPENTHREAD_CONFIG_LOG_LEVEL >= OPENTHREAD_LOG_LEVEL_INFO
#define otDumpInfo(aRegion, aId, aBuf, aLength)  otDump(kLogLevelInfo, aRegion, aId, aBuf, aLength)
#else
#define otDumpInfo(aRegion, aId, aBuf, aLength)
#endif

/**
 * @def otDumpDebg
 *
 * This method generates a memory dump with log level debug.
 *
 * @param[in]  aRegion  The log region.
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
#if OPENTHREAD_CONFIG_LOG_LEVEL >= OPENTHREAD_LOG_LEVEL_DEBG
#define otDumpDebg(aRegion, aId, aBuf, aLength)  otDump(kLogLevelDebg, aRegion, aId, aBuf, aLength)
#else
#define otDumpDebg(aRegion, aId, aBuf, aLength)
#endif

/**
 * @def otDumpCritNetData
 *
 * This method generates a memory dump with log level debug and region Network Data.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpWarnNetData
 *
 * This method generates a memory dump with log level warning and region Network Data.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpInfoNetData
 *
 * This method generates a memory dump with log level info and region Network Data.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpDebgNetData
 *
 * This method generates a memory dump with log level debug and region Network Data.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
#if OPENTHREAD_CONFIG_LOG_NETDATA == 1
#define otDumpCritNetData(aId, aBuf, aLength) otDumpCrit(kLogRegionNetData, aId, aBuf, aLength)
#define otDumpWarnNetData(aId, aBuf, aLength) otDumpWarn(kLogRegionNetData, aId, aBuf, aLength)
#define otDumpInfoNetData(aId, aBuf, aLength) otDumpInfo(kLogRegionNetData, aId, aBuf, aLength)
#define otDumpDebgNetData(aId, aBuf, aLength) otDumpDebg(kLogRegionNetData, aId, aBuf, aLength)
#else
#define otDumpCritNetData(aId, aBuf, aLength)
#define otDumpWarnNetData(aId, aBuf, aLength)
#define otDumpInfoNetData(aId, aBuf, aLength)
#define otDumpDebgNetData(aId, aBuf, aLength)
#endif

/**
 * @def otDumpCritMle
 *
 * This method generates a memory dump with log level debug and region MLE.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpWarnMle
 *
 * This method generates a memory dump with log level warning and region MLE.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpInfoMle
 *
 * This method generates a memory dump with log level info and region MLE.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpDebgMle
 *
 * This method generates a memory dump with log level debug and region MLE.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
#if OPENTHREAD_CONFIG_LOG_MLE == 1
#define otDumpCritMle(aId, aBuf, aLength) otDumpCrit(kLogRegionMle, aId, aBuf, aLength)
#define otDumpWarnMle(aId, aBuf, aLength) otDumpWarn(kLogRegionMle, aId, aBuf, aLength)
#define otDumpInfoMle(aId, aBuf, aLength) otDumpInfo(kLogRegionMle, aId, aBuf, aLength)
#define otDumpDebgMle(aId, aBuf, aLength) otDumpDebg(kLogRegionMle, aId, aBuf, aLength)
#else
#define otDumpCritMle(aId, aBuf, aLength)
#define otDumpWarnMle(aId, aBuf, aLength)
#define otDumpInfoMle(aId, aBuf, aLength)
#define otDumpDebgMle(aId, aBuf, aLength)
#endif

/**
 * @def otDumpCritArp
 *
 * This method generates a memory dump with log level debug and region EID-to-RLOC mapping.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpWarnArp
 *
 * This method generates a memory dump with log level warning and region EID-to-RLOC mapping.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpInfoArp
 *
 * This method generates a memory dump with log level info and region EID-to-RLOC mapping.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpDebgArp
 *
 * This method generates a memory dump with log level debug and region EID-to-RLOC mapping.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
#if OPENTHREAD_CONFIG_LOG_ARP == 1
#define otDumpCritArp(aId, aBuf, aLength) otDumpCrit(kLogRegionArp, aId, aBuf, aLength)
#define otDumpWarnArp(aId, aBuf, aLength) otDumpWarn(kLogRegionArp, aId, aBuf, aLength)
#define otDumpInfoArp(aId, aBuf, aLength) otDumpInfo(kLogRegionArp, aId, aBuf, aLength)
#define otDumpDebgArp(aId, aBuf, aLength) otDumpDebg(kLogRegionArp, aId, aBuf, aLength)
#else
#define otDumpCritArp(aId, aBuf, aLength)
#define otDumpWarnArp(aId, aBuf, aLength)
#define otDumpInfoArp(aId, aBuf, aLength)
#define otDumpDebgArp(aId, aBuf, aLength)
#endif

/**
 * @def otDumpCritIcmp
 *
 * This method generates a memory dump with log level debug and region ICMPv6.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpWarnIcmp
 *
 * This method generates a memory dump with log level warning and region ICMPv6.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpInfoIcmp
 *
 * This method generates a memory dump with log level info and region ICMPv6.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpDebgIcmp
 *
 * This method generates a memory dump with log level debug and region ICMPv6.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
#if OPENTHREAD_CONFIG_LOG_ICMP == 1
#define otDumpCritIcmp(aId, aBuf, aLength) otDumpCrit(kLogRegionIcmp, aId, aBuf, aLength)
#define otDumpWarnIcmp(aId, aBuf, aLength) otDumpWarn(kLogRegionIcmp, aId, aBuf, aLength)
#define otDumpInfoIcmp(aId, aBuf, aLength) otDumpInfo(kLogRegionIcmp, aId, aBuf, aLength)
#define otDumpDebgIcmp(aId, aBuf, aLength) otDumpDebg(kLogRegionIcmp, aId, aBuf, aLength)
#else
#define otDumpCritIcmp(aId, aBuf, aLength)
#define otDumpWarnIcmp(aId, aBuf, aLength)
#define otDumpInfoIcmp(aId, aBuf, aLength)
#define otDumpDebgIcmp(aId, aBuf, aLength)
#endif

/**
 * @def otDumpCritIp6
 *
 * This method generates a memory dump with log level debug and region IPv6.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpWarnIp6
 *
 * This method generates a memory dump with log level warning and region IPv6.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpInfoIp6
 *
 * This method generates a memory dump with log level info and region IPv6.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpDebgIp6
 *
 * This method generates a memory dump with log level debug and region IPv6.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
#if OPENTHREAD_CONFIG_LOG_IP6 == 1
#define otDumpCritIp6(aId, aBuf, aLength) otDumpCrit(kLogRegionIp6, aId, aBuf, aLength)
#define otDumpWarnIp6(aId, aBuf, aLength) otDumpWarn(kLogRegionIp6, aId, aBuf, aLength)
#define otDumpInfoIp6(aId, aBuf, aLength) otDumpInfo(kLogRegionIp6, aId, aBuf, aLength)
#define otDumpDebgIp6(aId, aBuf, aLength) otDumpDebg(kLogRegionIp6, aId, aBuf, aLength)
#else
#define otDumpCritIp6(aId, aBuf, aLength)
#define otDumpWarnIp6(aId, aBuf, aLength)
#define otDumpInfoIp6(aId, aBuf, aLength)
#define otDumpDebgIp6(aId, aBuf, aLength)
#endif

/**
 * @def otDumpCritMac
 *
 * This method generates a memory dump with log level debug and region MAC.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpWarnMac
 *
 * This method generates a memory dump with log level warning and region MAC.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpInfoMac
 *
 * This method generates a memory dump with log level info and region MAC.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpDebgMac
 *
 * This method generates a memory dump with log level debug and region MAC.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
#if OPENTHREAD_CONFIG_LOG_MAC == 1
#define otDumpCritMac(aId, aBuf, aLength) otDumpCrit(kLogRegionMac, aId, aBuf, aLength)
#define otDumpWarnMac(aId, aBuf, aLength) otDumpWarn(kLogRegionMac, aId, aBuf, aLength)
#define otDumpInfoMac(aId, aBuf, aLength) otDumpInfo(kLogRegionMac, aId, aBuf, aLength)
#define otDumpDebgMac(aId, aBuf, aLength) otDumpDebg(kLogRegionMac, aId, aBuf, aLength)
#else
#define otDumpCritMac(aId, aBuf, aLength)
#define otDumpWarnMac(aId, aBuf, aLength)
#define otDumpInfoMac(aId, aBuf, aLength)
#define otDumpDebgMac(aId, aBuf, aLength)
#endif

/**
 * @def otDumpCritMem
 *
 * This method generates a memory dump with log level debug and region memory.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpWarnMem
 *
 * This method generates a memory dump with log level warning and region memory.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpInfoMem
 *
 * This method generates a memory dump with log level info and region memory.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */

/**
 * @def otDumpDebgMem
 *
 * This method generates a memory dump with log level debug and region memory.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
#if OPENTHREAD_CONFIG_LOG_MEM == 1
#define otDumpCritMem(aId, aBuf, aLength) otDumpCrit(kLogRegionMem, aId, aBuf, aLength)
#define otDumpWarnMem(aId, aBuf, aLength) otDumpWarn(kLogRegionMem, aId, aBuf, aLength)
#define otDumpInfoMem(aId, aBuf, aLength) otDumpInfo(kLogRegionMem, aId, aBuf, aLength)
#define otDumpDebgMem(aId, aBuf, aLength) otDumpDebg(kLogRegionMem, aId, aBuf, aLength)
#else
#define otDumpCritMem(aId, aBuf, aLength)
#define otDumpWarnMem(aId, aBuf, aLength)
#define otDumpInfoMem(aId, aBuf, aLength)
#define otDumpDebgMem(aId, aBuf, aLength)
#endif

/**
 * @def otDumpCert
 *
 * This method generates a memory dump with log level none for the certification test.
 *
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
#if OPENTHREAD_ENABLE_CERT_LOG
#define otDumpCertMeshCoP(aId, aBuf, aLength) otDump(kLogLevelNone, kLogRegionMeshCoP, aId, aBuf, aLength)
#else
#define otDumpCertMeshCoP(aId, aBuf, aLength)
#endif

/**
 * This method dumps bytes to the log in a human-readable fashion.
 *
 * @param[in]  aLevel   The log level.
 * @param[in]  aRegion  The log region.
 * @param[in]  aId      A pointer to a NULL-terminated string that is printed before the bytes.
 * @param[in]  aBuf     A pointer to the buffer.
 * @param[in]  aLength  Number of bytes to print.
 *
 */
void otDump(otLogLevel aLevel, otLogRegion aRegion, const char *aId, const void *aBuf, const size_t aLength);

#if OPENTHREAD_CONFIG_LOG_PREPEND_LEVEL == 1
/**
* This method converts the log level value into a string
*
* @param[in]  aLevel  The log level.
*
* @returns A const char pointer to the C string corresponding to the log level.
*
*/
const char *otLogLevelToString(otLogLevel aLevel);
#endif

#if OPENTHREAD_CONFIG_LOG_PREPEND_REGION == 1
/**
 * This method converts the log region value into a string
 *
 * @param[in]  aRegion  The log region.
 *
 * @returns A const char pointer to the C string corresponding to the log region.
 *
 */
const char *otLogRegionToString(otLogRegion aRegion);
#endif

#if OPENTHREAD_CONFIG_LOG_PREPEND_LEVEL == 1

#if OPENTHREAD_CONFIG_LOG_PREPEND_REGION == 1

/**
 * Local/private macro to format the log message
 */
#define _otLogFormatter(aLogLevel, aRegion, aFormat, ...)                   \
    otPlatLog(                                                              \
        aLogLevel,                                                          \
        aRegion,                                                            \
        "[%s]%s: " aFormat OPENTHREAD_CONFIG_LOG_SUFFIX,                    \
        otLogLevelToString(aLogLevel),                                      \
        otLogRegionToString(aRegion),                                       \
        ## __VA_ARGS__                                                      \
    )

#else  // OPENTHREAD_CONFIG_LOG_PREPEND_REGION

/**
* Local/private macro to format the log message
*/
#define _otLogFormatter(aLogLevel, aRegion, aFormat, ...)                   \
    otPlatLog(                                                              \
        aLogLevel,                                                          \
        aRegion,                                                            \
        "[%s]: " aFormat OPENTHREAD_CONFIG_LOG_SUFFIX,                      \
        otLogLevelToString(aLogLevel),                                      \
        ## __VA_ARGS__                                                      \
    )

#endif

#else  // OPENTHREAD_CONFIG_LOG_PREPEND_LEVEL

#if OPENTHREAD_CONFIG_LOG_PREPEND_REGION == 1

/**
* Local/private macro to format the log message
*/
#define _otLogFormatter(aLogLevel, aRegion, aFormat, ...)                   \
    otPlatLog(                                                              \
        aLogLevel,                                                          \
        aRegion,                                                            \
        "%s: " aFormat OPENTHREAD_CONFIG_LOG_SUFFIX,                        \
        otLogRegionToString(aRegion),                                       \
        ## __VA_ARGS__                                                      \
    )

#else  // OPENTHREAD_CONFIG_LOG_PREPEND_REGION

/**
* Local/private macro to format the log message
*/
#define _otLogFormatter(aLogLevel, aRegion, aFormat, ...)                   \
    otPlatLog(                                                              \
        aLogLevel,                                                          \
        aRegion,                                                            \
        aFormat OPENTHREAD_CONFIG_LOG_SUFFIX,                               \
        ## __VA_ARGS__                                                      \
    )

#endif

#endif // OPENTHREAD_CONFIG_LOG_PREPEND_REGION

#ifdef __cplusplus
};
#endif

#endif  // LOGGING_HPP_
