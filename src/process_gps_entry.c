#include "process_gps.h"
#include "air_sensor_app.h"

char*       rmc_fields[13];
uint32_t    time_nw;

/* GPS entry function */
/* pvParameters contains TaskHandle_t */
void process_gps_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */

    L76_LB* p_gps = &air_sensor_app.gps;
    //First Init gps lat lon
    p_gps->lat = (float)21.0369234;
    p_gps->lon = (float)105.7874044;
    gps_app_init();

    while (1)
    {
        if(p_gps->is_new_msg == true){
            l76_lb_split_nmea_message(rmc_fields, p_gps->nmea_msg_buffer, ",");
            if(covert_lat_lon_to_float(rmc_fields[GNRMC_LAT], &p_gps->lat)
            		&& covert_lat_lon_to_float(rmc_fields[GNRMC_LON], &p_gps->lon))
            {
            	p_gps->gps_lat_lon_valid = true;
            }
            else
            {
            	p_gps->gps_lat_lon_valid = false;
            }

/*            time_nw = (uint32_t)atof(rmc_fields[GNRMC_UTC]);
            p_gps->gps_time.time.hour = (unsigned char)(time_nw / 10000) + 7;              // Shift to GMT+7
            if(p_gps->gps_time.time.hour >= 24) p_gps->gps_time.time.hour -= 24;
            if(p_gps->gps_time.time.hour != p_gps->real_time.hour.value){
                update_segment_data(&p_gps->real_time.hour, p_gps->gps_time.time.hour);
            }

            p_gps->gps_time.time.minute = (unsigned char)((time_nw % 10000) / 100);
            if(p_gps->gps_time.time.minute != p_gps->real_time.minute.value){
                update_segment_data(&p_gps->real_time.minute, p_gps->gps_time.time.minute);
            }

            p_gps->gps_time.time.sec = (unsigned char)(((time_nw % 10000) % 100));

            time_nw = (uint32_t)atof(rmc_fields[GNRMC_DAT]);
            p_gps->gps_time.time.date = (unsigned char)(time_nw / 10000);
            p_gps->gps_time.time.month = (unsigned char)((time_nw % 10000) / 100);
            p_gps->gps_time.time.year = (unsigned char)(((time_nw % 10000) % 100));*/

            p_gps->is_new_msg = false;
        }
        vTaskDelay(1);
    }

}
