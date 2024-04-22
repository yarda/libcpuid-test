/*
 * cpuid-test: cpuid example code.
 *
 * Based on the libcpuid example code:
 * https://libcpuid.sourceforge.net/documentation.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libcpuid.h>

int main(int argc, char *argv[])
{
  if (!cpuid_present()) {                 // check for CPUID presence
    printf("Sorry, your CPU doesn't support CPUID!\n");
    return -1;
  }

  if (argc > 1 && !strcmp(argv[1], "-l")) {
    struct cpu_list_t list;
    cpuid_get_cpu_list(cpuid_get_vendor(), &list);
    for (int x = 0; x < list.num_entries; x++)
      printf("%d: %s\n", x, list.names[x]);
    cpuid_free_cpu_list(&list);
    return EXIT_SUCCESS;
  }

  struct cpu_raw_data_t raw;              // contains only raw data
  struct cpu_id_t data;                   // contains recognized CPU features data

  if (cpuid_get_raw_data(&raw) < 0) {     // obtain the raw CPUID data
    printf("Sorry, cannot get the CPUID raw data.\n");
    printf("Error: %s\n", cpuid_error()); // cpuid_error() gives the last error description
    return -2;
  }

  if (cpu_identify(&raw, &data) < 0) {    // identify the CPU, using the given raw data.
    printf("Sorrry, CPU identification failed.\n");
    printf("Error: %s\n", cpuid_error());
    return -3;
  }

  printf("Found: %s CPU\n", data.vendor_str);                       // print out the vendor string (e.g. `GenuineIntel')
  printf("Processor model is `%s'\n", data.cpu_codename);           // print out the CPU code name (e.g. `Pentium 4 (Northwood)')
  printf("The full brand string is `%s'\n", data.brand_str);        // print out the CPU brand string
  printf("The processor has %dK L1 cache and %dK L2 cache\n",
    data.l1_data_cache, data.l2_cache);                             // print out cache size information
  printf("The processor has %d cores and %d logical processors\n",
    data.num_cores, data.num_logical_cpus);

  return EXIT_SUCCESS;
}
