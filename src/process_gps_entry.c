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
    p_gps->lat = (float)21.03719;
    p_gps->lon = (float)105.78835;
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

            p_gps->is_new_msg = false;
        }
        vTaskDelay(1);
    }

}
