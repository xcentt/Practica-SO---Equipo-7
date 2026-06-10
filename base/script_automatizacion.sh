#!/bin/bash

# Genera el timestamp (Año-Mes-Día_Hora-Minuto-Segundo)
TIMESTAMP=$(date +"%Y-%m-%d_%H-%M-%S")

# Define el nombre del archivo de log usando el timestamp
LOGFILE="salida_seccionB_${TIMESTAMP}.log"

echo "===================================================" > $LOGFILE
echo "Registro automatizado - Comandos Sección B" >> $LOGFILE
echo "Fecha y hora de ejecución: $(date)" >> $LOGFILE
echo "===================================================" >> $LOGFILE

echo -e "\n1. Salida de /proc/devices (Major numbers registrados):" >> $LOGFILE
cat /proc/devices >> $LOGFILE

echo -e "\n2. Salida de /proc/ioports (Puertos de E/S asignados):" >> $LOGFILE
cat /proc/ioports >> $LOGFILE

echo -e "\n3. Salida de /proc/iomem (Rangos de memoria asignados):" >> $LOGFILE
cat /proc/iomem >> $LOGFILE

echo -e "\n===================================================" >> $LOGFILE
echo "Ejecución finalizada correctamente." >> $LOGFILE

# Mensaje en consola para avisar que terminó
echo "¡Listo! Se ha generado el archivo: $LOGFILE"
