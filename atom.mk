LOCAL_PATH := $(call my-dir)

###############################################################################
# fake_ulog
###############################################################################

include $(CLEAR_VARS)

LOCAL_MODULE := libulog
LOCAL_DESCRIPTION := Simplistic reimplementation of libulog for code publication
LOCAL_CATEGORY_PATH := libs

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)

LOCAL_SRC_FILES := ulog.c

include $(BUILD_LIBRARY)

###############################################################################
# fake_ulogger
###############################################################################

include $(CLEAR_VARS)

LOCAL_MODULE := ulogger
LOCAL_DESCRIPTION := Reads stdin and rewrite to stderr
LOCAL_CATEGORY_PATH := utils

LOCAL_SRC_FILES := ulogger.c

include $(BUILD_EXECUTABLE)
