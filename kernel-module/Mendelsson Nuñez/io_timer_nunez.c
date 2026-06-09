#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/ktime.h>
#include <linux/timekeeping.h>

#define AUTHOR_NAME "Mendelsson Alejadro Nuñez Montoya"

MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR_NAME);
MODULE_DESCRIPTION("Modulo io_timer | Subsistema de Tiempo");

 // Función de inicialización (Carga del módulo)
int init_module(void)
{
    u64 time_ns;
    u64 uptime_ns;
    u64 diff_ns;

    printk(KERN_INFO "--- Iniciando modulo io_timer ---\n");

    // Obtener el timestamp del kernel en nanosegundos
    time_ns = ktime_get_ns();

    // Obtener el tiempo desde el arranque (Uptime)
    // Nota técnica: Leer el archivo VFS /proc/uptime directamente desde el kernel
    // es una mala práctica y riesgoso. La forma nativa y correcta en el kernel
    // para obtener el equivalente a /proc/uptime es usando ktime_get_boottime_ns().
    uptime_ns = ktime_get_boottime_ns();

    // Calcular si son consistentes
    if (uptime_ns > time_ns) {
        diff_ns = uptime_ns - time_ns;
    } else {
        diff_ns = time_ns - uptime_ns;
    }

    // Reportando ambos valores con printk
    printk(KERN_INFO "ktime_get() (Monotonico): %llu ns\n", time_ns);
    printk(KERN_INFO "Uptime (Boottime):        %llu ns\n", uptime_ns);

    // Análisis de consistencia
    if (diff_ns > 0) {
        printk(KERN_INFO "Consistencia: Hay una diferencia de %llu ns.\n", diff_ns);
    } else {
        printk(KERN_INFO "Consistencia: Los valores son exactamente iguales.\n");
    }

    return 0;
}

// Función de limpieza (Descarga del módulo)
void cleanup_module(void)
{
    // Imprimiendo mensaje de descarga con el nombre del autor
    printk(KERN_INFO "Modulo io_timer descargado. Autor: %s\n", AUTHOR_NAME);
}
