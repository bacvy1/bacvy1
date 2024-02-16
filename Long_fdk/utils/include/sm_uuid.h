//
// Created by vnbk on 12/04/2023.
//

#ifndef BSS_OTA_SERVICE_UUID_H
#define BSS_OTA_SERVICE_UUID_H

#ifdef __cplusplus
extern "C" {
#endif

char *sm_rand_string(char *str, int size);

const char* sm_get_uuid();

#ifdef __cplusplus
};
#endif

#endif //BSS_OTA_SERVICE_UUID_H
