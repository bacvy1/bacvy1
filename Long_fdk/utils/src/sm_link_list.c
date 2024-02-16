/*
 * list.c
 *
 *  Created on: Jul 14, 2023
 *      Author: Admin
 */


#include <sm_link_list.h>




link_list_t * sm_list_new(void* item,size_t size_item){

    link_list_t *node_current = (link_list_t*) malloc(sizeof(link_list_t));
    node_current->item = malloc(size_item);
    memcpy(node_current->item,item,size_item);
    node_current->size_item = size_item;
    node_current->next = NULL;
    return node_current;

}
void sm_list_delete(link_list_t *list){
    if(list == NULL) return;
    link_list_t *node = list->next;
    free(list->item);
    list->size_item = 0;
    free(list);
    if(node != NULL) list_delete(node);
}
int32_t sm_list_add(link_list_t *list,void* item){

    if(list->item == NULL) {
        list->item = item;
        list->next = NULL;
        return 0;
    }

    link_list_t *node_current = list;
    link_list_t *node_next = NULL;
    while(node_current->next != NULL){
    	node_current = node_current->next;;
    }
    node_current->next = list_new(item, node_current->size_item);
    return 0;
}
int32_t sm_list_remove(link_list_t *list,void *item){
    link_list_t *node = list;
    if(node == NULL) return -1;

    if(memcmp(node->item, item, node->size_item) == 0){
    	link_list_t *temp_node = node;
    	node = node->next;
    	free(temp_node);
    	return 0;
    }

    while(node->next != NULL){
        if(memcmp(node->next->item,item,node->next->size_item) == 0){
            link_list_t *temp_node = node->next;
            node->next = temp_node->next;
            free(temp_node);
            return 0;
        }
        node = node->next;
    }
    return -1;
}
