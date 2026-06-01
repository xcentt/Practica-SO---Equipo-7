#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/mm.h>

int init_module(void){
struct sysinfo si;
si_meminfo(&si);

printk(KERN_INFO "-----------------------------------------\n");
printk(KERN_INFO "Modulo cargado por Gabriel Pichardo. \n");

printk(KERN_INFO "Subsistema de memoria | Memoria Ram total: %lu MB/n", (si.totalram * si.mem_unit) / (1024 * 1024));
printk(KERN_INFO "Subsistema de memoria | Memoria Ram Libre: %lu MB/n", (si.freeram * si.mem_unit) / (1024 * 1024));
printk(KERN_INFO "-----------------------------------------/n");

return 0;

}

void cleanup_module(void){

printk(KERN_INFO "Modulo descargado con Exito. Autor: Gabriel Antonio Pichardo Raban");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gabriel Antonio Pichardo Raban");
MODULE_DESCRIPTION("Practica de Sistemas Operativo - Primer estudiante");

