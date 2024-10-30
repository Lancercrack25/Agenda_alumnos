#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
//funciones a usar en este proyecto
void cargando();
void saliendo();
void menu();
void grafico();
void inicio();
void capturar();
void mostrar();
void buscar();
void modificar();
void eliminar();
void Mensaje_modificacion();
void Mensaje_eliminacion();
//registro anidado para el llenado de la base de datos
struct agenda_alumnos{
    struct datos_personales{
        char nombre[35], domicilio[22], fracc[20], cp[6], ciudad[15],e_m[25], notas[2],sangre[2];
        int edad,telefono;
    }personales;

    struct datos_academicos{
        int codigo,semestre;
        float promedio;
        char carrera[25],centro_uni[9],ciclo[6];
    }academicos;
}alumno[10];
//menu principal
int main()
{
    setlocale(LC_ALL,"spanish");
    inicio();
    system("cls");
    printf("\t\t\t\t\tpulse <enter> para salir");
    return 0;
}
//funcion donde se ingresa la clave
int intentos =0;
void inicio()
{
    int clave= 123;
    while(clave == 123)
    {
        cargando();
        system("cls");
        system("color 0a");
        printf("\t\t\t\t\tIngrese la clave de acceso\n\t\t\t\t\t\t");
        scanf("%d",&clave);
        system("cls");

        if(clave != 123)
        {
            system("color 0c");
            printf("\t\t\tError, la clave que usted digito es incorrecta\n\t\t\tusted tiene %d/3 intentos disponibles\n",intentos+=1);
            if(intentos == 3)
            {
                system("cls");
                system("color 0c");
                printf("\t\t\t\tllegaste a tu limite de intentos");
                Sleep(1000);
                saliendo();
                break;
            }
            else
            {
              Sleep(2000);
              inicio();
            }

        }else
        {
            cargando();
            grafico();
            Sleep(2000);
            menu();
        }
    }
}
//funcion de pantalla de carga
void cargando()
{
    int i =1;
    for(i;i<=5;i++)
    {
        system("cls");
        system("color 0e");
        printf("\t\t\t\t\t\tCargando...");
        Sleep(800);
    }
    system("cls");
}
//funcion de pantalla de salida
void saliendo()
{
  int i=1;
  for(i;i<=5;i++){
    system("cls");
    system("color 0e");
    printf("\t\t\t\t\tsaliendo del sistema...");
    Sleep(800);
  }
  system("cls");
}
//menu cuando la clave es correcta el programa te digirge aqui
void menu()
{
    int opc;
    do
    {
        system("cls");
        system("color 1f");
        printf("<=====================================================================================================================>\n");
        printf("\t\t\t\t\t\t\tMenu\n");
        printf("\n<===================================================================================================================>\n");
        printf("\t\t\t\t\t\t¿Que deseas hacer?\n\n");
        printf("\t\t\t\t\t\t1.- Capturar\n\n\t\t\t\t\t\t2.- Mostrar\n\n\t\t\t\t\t\t3.- Buscar\n\n\t\t\t\t\t\t4.- Modificar\n\n\t\t\t\t\t\t5.- Eliminar\n\n\t\t\t\t\t\t6.- Salir\n\t\t\t\t\t\t");
        scanf("%d",&opc);
        system("cls");
        switch(opc)
        {
        case 1:
            cargando();
            capturar();
            break;
        case 2:
            cargando();
            mostrar();
            break;
        case 3:
            cargando();
            buscar();
            break;
        case 4:
            cargando();
            modificar();
            break;
        case 5:
            cargando();
            eliminar();
            break;
        case 6:
            printf("\t\t\t\t\t\teligio la opcion de salir");
            Sleep(2000);
            saliendo();
            return;
            break;
        default:
            system("cls");
            Sleep(400);
            printf("opcion no valida para este programa intente de nuevo");
            Sleep(2000);
        }
    }while(opc!=6);
}
//grafico despues de la pantalla de carga y antes de que te dirijan al menu
void grafico()
{
    system("cls");
    system("color 0e");
    Sleep(1000);
    printf("\t\t\t\t\t\t\t******\n");
    printf("\t\t\t\t\t\t\t******\n");
    printf("\t\t\t\t\t\t\t******\n");
    printf("\t\t\t\t\t\t\t------\n");
    printf("\t\t\t\t\t\t\t||||||\n");
    printf("\t\t\t\t\t\t\t||||||\n");
    printf("\t\t\t\t\t\t\t||||||\n");
    printf("\t\t\t\t\t\t\t||||||\n");
    printf("\t\t\t\t\t\t\t||||||\n");
    printf("\t\t\t\t\t\t\t||||||\n");
    printf("\t\t\t\t\t\t\t||||||\n");
    printf("\t\t\t\t\t\t\t||||||\n");
    printf("\t\t\t\t\t\t\t||||||\n");
    printf("\t\t\t\t\t\t\t||||||\n");
    printf("\t\t\t\t\t\t\t||||||\n");
    printf("\t\t\t\t\t\t\t******\n");
    printf("\t\t\t\t\t\t\t ***\n");
    printf("\t\t\t\t\t\t\t  *\n");
}
int limite = 0;//variable que determina el numero de registros
void capturar()
{
    if(limite<=10)
    {
        limite++;
        //registramos los datos personales del alumno
        system("color 1f");
        printf("\t\t\t\t\t\tRegistremos tus datos\n");
        printf("\t\t\t\t\t\tN° de registros: %d",limite);
        printf("\n<=================================================================================================================>\n");
        printf("\t\t\t\t\t\tDatos personales\n");
        printf("<==================================================================================================================>\n");
        fflush(stdin);
        printf("\n\t\t\t\t\t\tNombre:\n\t\t\t\t\t\t");
        gets(alumno[limite].personales.nombre);
        printf("\n\t\t\t\t\t\tDomicilio:\n\t\t\t\t\t\t");
        gets(alumno[limite].personales.domicilio);
        fflush(stdin);
        printf("\n\t\t\t\t\t\tfraccionamiento:\n\t\t\t\t\t\t");
        gets(alumno[limite].personales.fracc);
        printf("\n\t\t\t\t\t\tCodigo postal:\n\t\t\t\t\t\t");
        gets(alumno[limite].personales.cp);
        printf("\n\t\t\t\t\t\tCiudad:\n\t\t\t\t\t\t");
        gets(alumno[limite].personales.ciudad);
        printf("\n\t\t\t\t\t\tTelefono: \n\t\t\t\t\t\t");
        scanf("%d",&alumno[limite].personales.telefono);
        fflush(stdin);
        printf("\n\t\t\t\t\t\tEmail:\n\t\t\t\t\t\t");
        gets(alumno[limite].personales.e_m);
        printf("\n\t\t\t\t\t\tNotas:\n\t\t\t\t\t\t");
        gets(alumno[limite].personales.notas);
        printf("\n\t\t\t\t\t\tedad:\n\t\t\t\t\t\t");
        scanf("%d",&alumno[limite].personales.edad);
        fflush(stdin);
        printf("\n\t\t\t\t\t\tTipo de sangre:\n\t\t\t\t\t\t");
        gets(alumno[limite].personales.sangre);
        //pedimos los datos acaddemicos
        printf("\n<==================================================================================================================>\n");
        printf("\t\t\t\t\tDatos Academicos\n");
        printf("<==================================================================================================================>\n");
        printf("\n\t\t\t\t\tCodigo de estudiante:\n\t\t\t\t\t\t");
        scanf("%d",&alumno[limite].academicos.codigo);
        fflush(stdin);
        printf("\n\t\t\t\t\t\tCarrera:\n\t\t\t\t\t\t");
        gets(alumno[limite].academicos.carrera);
        printf("\n\t\t\t\t\t\tEscuela:\n\t\t\t\t\t\t");
        gets(alumno[limite].academicos.centro_uni);
        printf("\n\t\t\t\t\t\tPromedio:\n\t\t\t\t\t\t");
        scanf("%f",&alumno[limite].academicos.promedio);
        fflush(stdin);
        printf("\n\t\t\t\t\t\tSemestre:\n\t\t\t\t\t\t");
        scanf("%d",&alumno[limite].academicos.semestre);
        fflush(stdin);
        printf("\n\t\t\t\t\t\tCiclo escolar:\n\t\t\t\t\t\t");
        gets(alumno[limite].academicos.ciclo);
    }
    //en caso de que el contador de registros pase de 10 muestra este mensaje
    else
    {
        system("cls");
        printf("no hay espacio disponible en la base de datos, intente borrar algo que ya no le sea necesario para generar espacio");
    }
}
//funcion que muestra los datos capturados estos se meustran dependiendo de lo que el usuario haya escogido
void mostrar()
{
    int eleccion,i =1;
    if(limite!= 0)
    {
        system("color 0d");
        printf("\t\t\t\t\tQue es lo que desea que muestre?\n\n\t\t\t\t\t\t1.datos personales\n\n\t\t\t\t\t\t2.datos academicos\n\n\t\t\t\t\t\t3.ambos\n\t\t\t\t\t\t");
        scanf("%d",&eleccion);
        system("cls");
        switch(eleccion)
        {
        case 1:
            printf("\n\t\t\t\t\tAqui estan los datos personales de los registrados\n");
            printf("\n<==================================================================================================================>\n");
            for(i;i<=limite;i++)
            {
                printf("\n\t\t\t\t\t\tNombre: %s\n\t\t\t\t\t\t",alumno[i].personales.nombre);
                printf("\n\t\t\t\t\t\tDomicilio: %s\n\t\t\t\t\t\t",alumno[i].personales.domicilio);
                printf("\n\t\t\t\t\t\tfraccionamiento: %s\n\t\t\t\t\t\t",alumno[i].personales.fracc);
                printf("\n\t\t\t\t\t\tCodigo postal: %s\n\t\t\t\t\t\t",alumno[i].personales.cp);
                printf("\n\t\t\t\t\t\tCiudad: %s\n\t\t\t\t\t\t",alumno[i].personales.ciudad);
                printf("\n\t\t\t\t\t\tTelefono: %d\n\t\t\t\t\t\t",alumno[i].personales.telefono);
                printf("\n\t\t\t\t\t\tEmail: %s\n\t\t\t\t\t\t",alumno[i].personales.e_m);
                printf("\n\t\t\t\t\t\tNotas: %s\n\t\t\t\t\t\t",alumno[i].personales.notas);
                printf("\n\t\t\t\t\t\tEdad: %d\n\t\t\t\t\t\t",alumno[i].personales.edad);
                printf("\n\t\t\t\t\t\ttipo de sangre: %s\n\t\t\t\t\t\t",alumno[i].personales.sangre);
                printf("\n<==================================================================================================================>\n");
                printf("\n\n");
            }
            Sleep(9000);
            break;
        case 2:
            printf("Aqui estan los datos academicos de los registrados\n");
            printf("\n<==================================================================================================================>\n");
            for(i;i<=limite;i++)
            {
                printf("\n\t\t\t\t\t\tCodigo del estudiante: %d\n\t\t\t\t\t\t",alumno[i].academicos.codigo);
                printf("\n\t\t\t\t\t\tCarrera: %s\n\t\t\t\t\t\t",alumno[i].academicos.carrera);
                printf("\n\t\t\t\t\t\tEscuela: %s\n\t\t\t\t\t\t",alumno[i].academicos.centro_uni);
                printf("\n\t\t\t\t\t\tPromedio: %.2f\n\t\t\t\t\t\t",alumno[i].academicos.promedio);
                printf("\n\t\t\t\t\t\tSemestre: %d\n\t\t\t\t\t\t",alumno[i].academicos.semestre);
                printf("\n\t\t\t\t\t\tCiclo escolar: %s\n\t\t\t\t\t\t",alumno[i].academicos.ciclo);
                printf("\n<==================================================================================================================>\n");
            }
            Sleep(9000);
            break;
        case 3:
            printf("Aqui estan los datos personales y academicos de los registrados\n");
            printf("\n<==================================================================================================================>\n");
            for(i;i<=limite;i++)
            {
                printf("\n\t\t\t\t\t\tDatos personales\n");
                printf("<==================================================================================================================>\n");
                printf("\t\t\t\t\t\tNombre: %s\n\t\t\t\t\t\t",alumno[i].personales.nombre);
                printf("\n\t\t\t\t\t\tDomicilio: %s\n\t\t\t\t\t\t",alumno[i].personales.domicilio);
                printf("\n\t\t\t\t\t\tfraccionamiento: %s\n\t\t\t\t\t\t",alumno[i].personales.fracc);
                printf("\n\t\t\t\t\t\tCodigo postal: %s\n\t\t\t\t\t\t",alumno[i].personales.cp);
                printf("\n\t\t\t\t\t\tCiudad: %s\n\t\t\t\t\t\t",alumno[i].personales.ciudad);
                printf("\n\t\t\t\t\t\tTelefono: %d\n\t\t\t\t\t\t",alumno[i].personales.telefono);
                printf("\n\t\t\t\t\t\tEmail: %s\n\t\t\t\t\t\t",alumno[i].personales.e_m);
                printf("\n\t\t\t\t\t\tNotas: %s\n\t\t\t\t\t\t",alumno[i].personales.notas);
                printf("Edad: %d\n",alumno[i].personales.edad);
                printf("\n\t\t\t\t\t\ttipo de sangre: %s\n\t\t\t\t\t\t",alumno[i].personales.sangre);
                printf("\n\t\t\t\t\t\tDatos academicos\n\t\t\t\t\t\t");
                printf("\n\t\t\t\t\tCodigo del estudiante: %d\n\t\t\t\t\t\t",alumno[i].academicos.codigo);
                printf("\n\t\t\t\t\t\tCarrera: %s\n\t\t\t\t\t\t",alumno[i].academicos.carrera);
                printf("\n\t\t\t\t\t\tEscuela: %s\n\t\t\t\t\t\t",alumno[i].academicos.centro_uni);
                printf("\n\t\t\t\t\t\tPromedio: %.2f\n\t\t\t\t\t\t",alumno[i].academicos.promedio);
                printf("\n\t\t\t\t\t\tSemestre: %d\n\t\t\t\t\t\t",alumno[i].academicos.semestre);
                printf("\n\t\t\t\t\t\tCiclo escolar: %s\n\t\t\t\t\t\t",alumno[i].academicos.ciclo);
                printf("\n<==================================================================================================================>\n");
                printf("\n\n");

            }
            Sleep(9000);
            break;
        default:
            printf("\n\t\t\t\t\tOpcion no valida intente de nuevo");
            Sleep(2000);
            mostrar();
        }
    }
    //en el caso de que nadie este registrado, la variable que cuenta el numero de registros sea 0 ejecuta estas instrucciones
    else
    {
        system("cls");
        system("color 0c");
        printf("\t\t\t\tLa base de datos esta vacia intente llenarla porfavor...");
        Sleep(2000);
        system("cls");
        capturar();
    }
}
//funcion que realiza una busqueda en la base de datos
void buscar()
{
    char nombre[35];
    int i = 0;
    if(limite!=0)
    {
      fflush(stdin);
      system("color 03");
      printf("\n\t\t\tIngresa el nombre del alumno el cual desees realizar su busqueda\n\t\t\t\t\t\t");
      gets(nombre);
      system("cls");
      printf("\n\t\t\t\t\tAqui tienes los resultados de tu busqueda\n");
      printf("\n<==================================================================================================================>\n");
      for(i;i<=limite;i++)
      {
          fflush(stdin);
          if(strcmp(nombre,alumno[i].personales.nombre)== 0)
          {

            printf("\t\t\t\t\t\tDatos personales\n");
            printf("\n<==================================================================================================================>\n");
            printf("\t\t\t\t\t\tNombre: %s\n\t\t\t\t\t\t",alumno[i].personales.nombre);
            printf("\n\t\t\t\t\t\tDomicilio: %s\n\t\t\t\t\t\t",alumno[i].personales.domicilio);
            printf("\n\t\t\t\t\t\tfraccionamiento: %s\n\t\t\t\t\t\t",alumno[i].personales.fracc);
            printf("\n\t\t\t\t\t\tCodigo postal: %s\n\t\t\t\t\t\t",alumno[i].personales.cp);
            printf("\n\t\t\t\t\t\tCiudad: %s\n\t\t\t\t\t\t",alumno[i].personales.ciudad);
            printf("\n\t\t\t\t\t\tTelefono: %d\n\t\t\t\t\t\t",alumno[i].personales.telefono);
            printf("\n\t\t\t\t\t\tEmail: %s\n\t\t\t\t\t\t",alumno[i].personales.e_m);
            printf("\n\t\t\t\t\t\tNotas: %s\n\t\t\t\t\t\t",alumno[i].personales.notas);
            printf("\n\t\t\t\t\t\tEdad: %d\n\t\t\t\t\t\t",alumno[i].personales.edad);
            printf("\n\t\t\t\t\t\ttipo de sangre: %s\n\t\t\t\t\t\t",alumno[i].personales.sangre);
            //ademas de los datos personales tambien se buscan los academicos del registrado seleccionado
            printf("\n<==================================================================================================================>\n");
            printf("\t\t\t\t\t\tDatos academicos\n");
            printf("<==================================================================================================================>\n");
            printf("\t\t\t\t\t\tCodigo del estudiante: %d\n\t\t\t\t\t\t",alumno[i].academicos.codigo);
            printf("\n\t\t\t\t\t\tCarrera: %s\n\t\t\t\t\t\t",alumno[i].academicos.carrera);
            printf("\n\t\t\t\t\t\tEscuela: %s\n\t\t\t\t\t\t",alumno[i].academicos.centro_uni);
            printf("\n\t\t\t\t\t\tPromedio: %.2f\n\t\t\t\t\t\t",alumno[i].academicos.promedio);
            printf("\n\t\t\t\t\t\tSemestre: %d\n\t\t\t\t\t\t",alumno[i].academicos.semestre);
            printf("\n\t\t\t\t\t\tCiclo escolar: %s\n\t\t\t\t\t\t",alumno[i].academicos.ciclo);
            printf("\n<==================================================================================================================>\n");
          }
          fflush(stdin);
      }
      //en el caso de que el nombre ingresado no coincida con lo que hay en la base de datos ejecuta esto
      if(i==limite)
      {
          printf("\n\t\t\t\t\t\tel nombre ingresado no coincide con la base de datos\n");
          printf("\n\t\t\t\tIntente de nuevo o registre a ese alumno del que desea realizar su busqueda\n");
      }
      Sleep(8000);

    }
    //caso en el que nadie este registrado le muestra un mensaje y dirige al usuario a capturar datos para que haya registros en la base de datos
    else
    {
      system("color 0c");
      printf("\t\t\t\tNo se puede realizar ninguna busqueda ya que nadie esta registrado...");
      Sleep(3000);
      system("cls");
      capturar();
    }
}
//funcion para modificar la base de datos
void modificar()
{
    char nombre[35],domicilio[22], fracc[20], cp[6], ciudad[15],e_m[25], notas[2],sangre[2],carrera[25],centro_uni[9],ciclo[6];
    int i = 0,eleccion,edad,tel,codigo,semestre;
    float prom;
    if(limite!=0)
    {
      fflush(stdin);
      system("color 0f");
      printf("\n\t\tIngresa el nombre del alumno el cual desees realizar una modificacion de sus datos\n\t\t\t\t");
      gets(nombre);
      system("cls");
      printf("\t\t\t\tAqui tienes los resultados de tu busqueda\n");
      printf("\n<==================================================================================================================>\n");
      for(i;i<=limite;i++)
      {
          if(strcmp(nombre,alumno[i].personales.nombre)== 0)
          {
            fflush(stdin);
            printf("\t\t\t\t\tDatos personales\n");
            printf("\n<==================================================================================================================>\n");
            printf("\n\t\t\t\t\tNombre: %s\n\t\t\t\t\t",alumno[i].personales.nombre);
            printf("\n\t\t\t\t\tDomicilio: %s\n\t\t\t\t\t",alumno[i].personales.domicilio);
            printf("\n\t\t\t\t\tfraccionamiento: %s\n\t\t\t\t\t",alumno[i].personales.fracc);
            printf("\n\t\t\t\t\tCodigo postal: %s\n\t\t\t\t\t",alumno[i].personales.cp);
            printf("\n\t\t\t\t\tCiudad: %s\n\t\t\t\t\t",alumno[i].personales.ciudad);
            printf("\n\t\t\t\t\tTelefono: %d\n\t\t\t\t\t",alumno[i].personales.telefono);
            printf("\n\t\t\t\t\tEmail: %s\n\t\t\t\t\t",alumno[i].personales.e_m);
            printf("\n\t\t\t\t\tNotas: %s\n\t\t\t\t\t",alumno[i].personales.notas);
            printf("\n\t\t\t\t\tEdad: %d\n\t\t\t\t\t",alumno[i].personales.edad);
            printf("\n\t\t\t\t\ttipo de sangre: %s\n\t\t\t\t\t",alumno[i].personales.sangre);
            //ademas de los datos personales tambien se buscan los academicos del registrado seleccionado
            printf("\n<==================================================================================================================>\n");
            printf("\n\t\t\t\t\tDatos academicos\n");
            printf("<==================================================================================================================>\n");
            printf("\n\t\t\t\tCodigo del estudiante: %d\n\t\t\t\t\t",alumno[i].academicos.codigo);
            printf("\n\t\t\t\t\tCarrera: %s\n\t\t\t\t\t",alumno[i].academicos.carrera);
            printf("\n\t\t\t\t\tEscuela: %s\n\t\t\t\t\t",alumno[i].academicos.centro_uni);
            printf("\n\t\t\t\t\tPromedio: %d\n\t\t\t\t\t",alumno[i].academicos.promedio);
            printf("\n\t\t\t\t\tSemestre: %.2f\n\t\t\t\t\t",alumno[i].academicos.semestre);
            printf("\n\t\t\t\t\tCiclo escolar: %s\n\t\t\t\t\t",alumno[i].academicos.ciclo);
            printf("\n\n");
            fflush(stdin);
            printf("\t\t\t\t\tQue campo deseas modificar?\n\t\t\t\t\t1.Nombre\n\t\t\t\t\t2.Domicilio\n\t\t\t\t\t3.Fraccionamineto\n\t\t\t\t\t4.Codigo postal\n\t\t\t\t\t5.Ciudad\n\t\t\t\t\t6.Telefono\n\t\t\t\t\t7.Email\n\t\t\t\t\t8.Notas\n\t\t\t\t\t9.Edad\n\t\t\t\t\t10.Tipo de sangre\n\t\t\t\t\t11.codigo de estudiante\n\t\t\t\t\t12.Carrera\n\t\t\t\t\t13.Escuela\n\t\t\t\t\t14.Promedio\n\t\t\t\t\t15.semestre\n\t\t\t\t\t16.Ciclo escolar\n\t\t\t\t\t17.Todos\n\t\t\t\t\t18.Ninguno\n\t\t\t\t\t");
            scanf("%d",&eleccion);
            system("cls");
            switch(eleccion)
            {
            case 1:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Nombre\n\t\t\t\t\t");
               gets(nombre);
               strcpy(alumno[i].personales.nombre,nombre);
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
            case 2:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Domicilio\n\t\t\t\t\t");
               gets(domicilio);
               strcpy(alumno[i].personales.domicilio,domicilio);
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
            case 3:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo fraccionamiento\n\t\t\t\t\t");
               gets(fracc);
               strcpy(alumno[i].personales.fracc,fracc);
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
            case 4:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Codigo postal\n\t\t\t\t\t");
               gets(cp);
               strcpy(alumno[i].personales.cp,cp);
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
            case 5:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Ciudad\n\t\t\t\t\t");
               gets(ciudad);
               strcpy(alumno[i].personales.ciudad,ciudad);
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
           case 6:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Telefono\n\t\t\t\t\t");
               scanf("%d",&tel);
               alumno[i].personales.telefono=tel;
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
           case 7:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Email\n\t\t\t\t\t");
               gets(e_m);
               strcpy(alumno[i].personales.e_m,e_m);
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
           case 8:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Notas\n\t\t\t\t\t");
               gets(notas);
               strcpy(alumno[i].personales.notas,notas);
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
           case 9:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Edad\n\t\t\t\t\t");
               scanf("%d",&edad);
               alumno[i].personales.edad=edad;
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
           case 10:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Tipo de sangre\n\t\t\t\t\t");
               gets(sangre);
               strcpy(alumno[i].personales.sangre,sangre);
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
           case 11:
               fflush(stdin);
               printf("\t\t\t\tIngresa el nuevo valor para el campo codigo estudiante\n\t\t\t\t\t");
               scanf("%d",&codigo);
               alumno[i].academicos.codigo=codigo;
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
           case 12:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Carrera\n\t\t\t\t\t");
               gets(carrera);
               strcpy(alumno[i].academicos.carrera,carrera);
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
           case 13:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Escuela\n\t\t\t\t\t");
               gets(centro_uni);
               strcpy(alumno[i].academicos.centro_uni,centro_uni);
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
              break;
           case 14:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Promedio\n\t\t\t\t\t");
               scanf("%f",&prom);
               alumno[i].academicos.promedio = prom;
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
           case 15:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Semestre\n\t\t\t\t\t");
               scanf("%d",&semestre);
               alumno[i].academicos.semestre = semestre;
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
           case 16:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Ciclo escolar\n\t\t\t\t\t");
               gets(ciclo);
               strcpy(alumno[i].academicos.ciclo,ciclo);
               Sleep(1000);
               Mensaje_modificacion();
               modificar();
               break;
           case 17:
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Nombre\n\t\t\t\t\t");
               gets(nombre);
               strcpy(alumno[i].personales.nombre,nombre);
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Domicilio\n\t\t\t\t\t");
               gets(domicilio);
               strcpy(alumno[i].personales.domicilio,domicilio);
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo fraccionamiento\n\t\t\t\t\t");
               gets(fracc);
               strcpy(alumno[i].personales.fracc,fracc);
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Codigo postal\n\t\t\t\t\t");
               gets(cp);
               strcpy(alumno[i].personales.cp,cp);
               Sleep(5000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Ciudad\n\t\t\t\t\t");
               gets(ciudad);
               strcpy(alumno[i].personales.ciudad,ciudad);
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Telefono\n\t\t\t\t\t");
               scanf("%d",&tel);
               alumno[i].personales.telefono = tel;
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Email\n\t\t\t\t\t");
               gets(e_m);
               strcpy(alumno[i].personales.e_m,e_m);
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Notas\n\t\t\t\t\t");
               gets(notas);
               strcpy(alumno[i].personales.notas,notas);
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Edad\n\t\t\t\t\t");
               scanf("%d",&edad);
               alumno[i].personales.edad = edad;
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Tipo de sangre\n\t\t\t\t\t");
               gets(sangre);
               strcpy(alumno[i].personales.sangre,sangre);
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo codigo estudiante\n\t\t\t\t\t");
               scanf("%d",&codigo);
               alumno[i].academicos.codigo = codigo;
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Carrera\n\t\t\t\t\t");
               gets(carrera);
               strcpy(alumno[i].academicos.carrera,carrera);
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Escuela\n\t\t\t\t\t");
               gets(centro_uni);
               strcpy(alumno[i].academicos.centro_uni,centro_uni);
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Promedio\n\t\t\t\t\t");
               scanf("%f",&prom);
               alumno[i].academicos.promedio = prom;
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Semestre\n\t\t\t\t\t");
               scanf("%d",&semestre);
               alumno[i].academicos.semestre = semestre;
               Sleep(1000);
               fflush(stdin);
               printf("\t\t\t\t\tIngresa el nuevo valor para el campo Ciclo escolar\n\t\t\t\t\t");
               gets(ciclo);
               strcpy(alumno[i].academicos.ciclo,ciclo);
               Sleep(1000);
               Mensaje_modificacion();
               fflush(stdin);
               break;
           case 18:
               cargando();
               menu();
               break;
           default:
               printf("\t\t\t\t\tOpcion no valida, intente de nuevo");
               Sleep(2000);
               system("cls");
               modificar();
           }
          }
      }
      //en el caso de que el nombre ingresado no coincida con lo que hay en la base de datos ejecuta esto
      if(i == limite)
      {
          printf("\t\t\tel nombre ingresado no coincide con la base de datos\n");
          printf("\tIntente de nuevo o registre a ese alumno del que desea realizar su busqueda\n");
          Sleep(3000);
          menu();
      }
    }
    else
    {
        system("color 0c");
        printf("\tNo se puede realizar ninguna modificacion al registro ya que nadie esta registrado aun...");
        Sleep(3000);
        system("cls");
        capturar();
    }
}
//funcion que elimina datos de la base de datos
void eliminar() {
    char name[30];
    int i;

    if (limite != 0) {
        fflush(stdin);
        printf("\t\tIngresa el nombre del alumno que desees eliminar de la base de datos\n\t\t\t\t\t");
        gets(name);
        system("cls");

        for (i = 0; i <=limite; i++)
        {
            if (strcmp(name, alumno[i].personales.nombre) == 0)
            {
                alumno[i] = alumno[i + 1];
                limite--;
                Mensaje_eliminacion();
                Sleep(1000);
                return;  // Importante salir de la función después de la eliminación
            }
        }
        if(i == limite)
            {
                printf("\t\tEl nombre no coincide con tu búsqueda, intenta de nuevo o registra a un alumno");
                Sleep(2000);
                system("cls");
                menu();
            }
    }
    else
    {
        system("color 0c");
        printf("\tNo se puede realizar ninguna eliminación al registro ya que nadie está registrado aún...");
        Sleep(3000);
        system("cls");
        capturar();
    }
}

//funcion que muestra mensajes de cuando se realizan cambios en el registro
void Mensaje_modificacion()
{
    int i =1;
    for(i;i<=5;i++)
    {
        system("cls");
        system("color 0e");
        printf("\t\t\tRealizando modificacion en la base de datos...");
        Sleep(800);
    }
    Sleep(2000);
    system("cls");
    printf("\t\t\tla modificacion en la base de datos se realizo exitosamente.");
    Sleep(2000);
    system("cls");
}
//mensaje que se muestra despues de realizar una eliminacion de los registrados
void Mensaje_eliminacion()
{
    int i =1;
    for(i;i<=5;i++)
    {
        system("cls");
        system("color 0e");
        printf("\t\t\t\t\tEliminando datos...");
        Sleep(800);
    }
    Sleep(2000);
    system("cls");
    printf("\t\t\tLos datos fueron borrados del registro.");
    Sleep(2000);
    system("cls");
}
