.section	.text
str_println:	.asciz "%s\n"
str1:		.asciz "Sort successful"
str2:		.asciz "Sort failed"

.global main
main:
	push	{lr}
	ldr	r0, =str1
	bl	printf
	ldr	r1, =str2
	ldr	r0, =str_println
	bl	printf
	pop	{pc}
