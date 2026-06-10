#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/ktime.h>
#include <linux/timekeeping.h>

#define AUTHOR_NAME "Gabriel Antonio Pichardo Raban"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AUTHOR_NAME");
MODULE_DESCRIPTION("Subsistema de tiempo IO Timer");


// Este modulo nos sirve para inicializar y cargar nuestro modulo
int init_module(void){

u64 time_ns;
u64 uptime_ns;
u64 diff_ns;

printk(KERN_INFO "--------------------------------------\n");

//Obtenemos el timestamp en nano segundos
time_ns = ktime_get_ns();

//Ahora obtenemos el tiempo desde el arranque

uptime_ns = ktime_get_boottime_ns();

//Calculamos si los resultados son consistentes

if (uptime_ns > time_ns){

diff_ns = uptime_ns - time_ns;
}else {

diff_ns = time_ns - uptime_ns;
}


//Ahora imprimimos ambos valores

printk(KERN_INFO "ktime_get() (Monotonico): %llu ns\n", time_ns);
printk(KERN_INFO "Uptime (Boottime): %llu ns\n", uptime_ns);


//Analizamos la  consistencia de nuestros resultados

if(diff_ns > 0){
printk(KERN_INFO "Consistencia: Hay una diferencia de: %llu ns.\n", diff_ns);
}else{
printk(KERN_INFO "Consistencia: Los valores son iguales. \n");

}

return 0;
}

//Funcion de limpieza
void cleanup_module(void){

//Mandamos a mostrar en pantalla el mensaje de descarga con el nombre del autor

printk(KERN_INFO "Modulo io_timer Descargado. Autor %s\n", AUTHOR_NAME);
}
