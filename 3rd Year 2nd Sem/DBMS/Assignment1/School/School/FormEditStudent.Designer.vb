<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormEditStudent
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.edit_dcode = New System.Windows.Forms.TextBox()
        Me.edit_name = New System.Windows.Forms.TextBox()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.search_edit = New System.Windows.Forms.Button()
        Me.edit_roll = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.edit_cancel = New System.Windows.Forms.Button()
        Me.edit_save = New System.Windows.Forms.Button()
        Me.edit_dept = New System.Windows.Forms.ComboBox()
        Me.SuspendLayout()
        '
        'edit_dcode
        '
        Me.edit_dcode.Location = New System.Drawing.Point(371, 278)
        Me.edit_dcode.Name = "edit_dcode"
        Me.edit_dcode.ReadOnly = True
        Me.edit_dcode.Size = New System.Drawing.Size(258, 20)
        Me.edit_dcode.TabIndex = 17
        '
        'edit_name
        '
        Me.edit_name.Location = New System.Drawing.Point(371, 172)
        Me.edit_name.Name = "edit_name"
        Me.edit_name.Size = New System.Drawing.Size(258, 20)
        Me.edit_name.TabIndex = 15
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.Location = New System.Drawing.Point(125, 278)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(163, 24)
        Me.Label4.TabIndex = 14
        Me.Label4.Text = "Department Code:"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.Location = New System.Drawing.Point(125, 222)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(112, 24)
        Me.Label3.TabIndex = 13
        Me.Label3.Text = "Department:"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(125, 169)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(66, 24)
        Me.Label2.TabIndex = 12
        Me.Label2.Text = "Name:"
        '
        'search_edit
        '
        Me.search_edit.Location = New System.Drawing.Point(627, 84)
        Me.search_edit.Name = "search_edit"
        Me.search_edit.Size = New System.Drawing.Size(92, 23)
        Me.search_edit.TabIndex = 11
        Me.search_edit.Text = "Search"
        Me.search_edit.UseVisualStyleBackColor = True
        '
        'edit_roll
        '
        Me.edit_roll.Location = New System.Drawing.Point(371, 87)
        Me.edit_roll.Name = "edit_roll"
        Me.edit_roll.Size = New System.Drawing.Size(186, 20)
        Me.edit_roll.TabIndex = 10
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(80, 84)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(171, 24)
        Me.Label1.TabIndex = 9
        Me.Label1.Text = "Enter Roll Number:"
        '
        'edit_cancel
        '
        Me.edit_cancel.Location = New System.Drawing.Point(222, 354)
        Me.edit_cancel.Name = "edit_cancel"
        Me.edit_cancel.Size = New System.Drawing.Size(130, 23)
        Me.edit_cancel.TabIndex = 18
        Me.edit_cancel.Text = "Cancel"
        Me.edit_cancel.UseVisualStyleBackColor = True
        '
        'edit_save
        '
        Me.edit_save.Enabled = False
        Me.edit_save.Location = New System.Drawing.Point(404, 354)
        Me.edit_save.Name = "edit_save"
        Me.edit_save.Size = New System.Drawing.Size(130, 23)
        Me.edit_save.TabIndex = 19
        Me.edit_save.Text = "Save"
        Me.edit_save.UseVisualStyleBackColor = True
        '
        'edit_dept
        '
        Me.edit_dept.FormattingEnabled = True
        Me.edit_dept.Location = New System.Drawing.Point(371, 222)
        Me.edit_dept.Name = "edit_dept"
        Me.edit_dept.Size = New System.Drawing.Size(258, 21)
        Me.edit_dept.TabIndex = 20
        '
        'FormEditStudent
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.edit_dept)
        Me.Controls.Add(Me.edit_save)
        Me.Controls.Add(Me.edit_cancel)
        Me.Controls.Add(Me.edit_dcode)
        Me.Controls.Add(Me.edit_name)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.search_edit)
        Me.Controls.Add(Me.edit_roll)
        Me.Controls.Add(Me.Label1)
        Me.Name = "FormEditStudent"
        Me.Text = "FormEditStudent"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents edit_dcode As TextBox
    Friend WithEvents edit_name As TextBox
    Friend WithEvents Label4 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents search_edit As Button
    Friend WithEvents edit_roll As TextBox
    Friend WithEvents Label1 As Label
    Friend WithEvents edit_cancel As Button
    Friend WithEvents edit_save As Button
    Friend WithEvents edit_dept As ComboBox
End Class
