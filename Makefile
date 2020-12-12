keymap := "quefrency-rev1-60"
qmk_dir := $(shell find $$HOME -name 'qmk_firmware')
sub_dir := "$(qmk_dir)/keyboards/keebio/quefrency/keymaps/$(keymap)"

.check:
	@echo Checking qmk_firmware repository exists...
	[ ! -z "$(qmk_dir)" ]
	@echo $(qmk_dir)
	@echo OK
	@echo Checking if keymap is in expected location:
	@echo $(sub_dir)
	[ $(sub_dir) == $(shell pwd) ]
	@echo OK

.config:
	@echo Comparing rules.mk...
	bash -c "comm -2 <(grep -v '^$$\|^#' rules.mk | sort) <(grep -v '^$$\|^#' ../../rules.mk | sort | cut -d ' ' -f-3)"
	@echo DONE

default: .check .config
	@echo Building keymap...
	(cd $(qmk_dir) && make keebio/quefrency:$(keymap))
	@echo OK

flash:
	@echo Building and flashing keymap...
	(cd $(qmk_dir) && sudo make keebio/quefrency:$(keymap):dfu)
	@echo OK

ifndef VERBOSE
.SILENT:
endif
