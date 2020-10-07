.PHONY: clean All

All:
	@echo "----------Building project:[ VisitaSimmetrica - Debug ]----------"
	@cd "VisitaSimmetrica" && "$(MAKE)" -f  "VisitaSimmetrica.mk"
clean:
	@echo "----------Cleaning project:[ VisitaSimmetrica - Debug ]----------"
	@cd "VisitaSimmetrica" && "$(MAKE)" -f  "VisitaSimmetrica.mk" clean
