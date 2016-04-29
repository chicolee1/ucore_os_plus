#ifndef JOS_DEV_PCI_H
#define JOS_DEV_PCI_H

#include <types.h>

// PCI subsystem interface
enum { pci_res_bus, pci_res_mem, pci_res_io, pci_res_max };

struct pci_bus;

struct pci_func {
    struct pci_bus *bus;	// Primary bus for bridges

    uint32_t dev;
    uint32_t func;

    uint32_t dev_id;
    uint32_t dev_class;

    uint32_t reg_base[6];
    uint32_t reg_size[6];
    uint8_t irq_line;
};

struct pci_bus {
    struct pci_func *parent_bridge;
    uint32_t busno;
};

struct net_device_ops {
	void			(*transmit_pkt) (void *buf, int size); 
};

int pci_init(void);
void pci_func_enable(struct pci_func *f);

#endif
