Imports School.StudentList
Public Class FormAddStudent


    Private Sub FormAddStudent_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ' Populate combo box
        For stepper = 0 To (depts.Count - 1)
            dept.Items.Add(depts(stepper))
        Next

        ' Set roll number value
        roll_no.Text = maxRoll

    End Sub

    Private Sub dept_SelectedIndexChanged(sender As Object, e As EventArgs) Handles dept.SelectedIndexChanged
        ' Set dept code
        dcode.Text = deptCode(dept.SelectedIndex)
    End Sub

    Private Sub btn_cancel_Click(sender As Object, e As EventArgs) Handles btn_cancel.Click
        ' Simply close the form
        Me.Close()
    End Sub

    Private Sub btn_save_Click(sender As Object, e As EventArgs) Handles btn_save.Click
        If (name_st.Text = "" Or dept.Text = "" Or Not depts.contains(dept.Text)) Then
            MessageBox.Show("Enter valid name and department")
        Else
            stList.Add(New Student(roll_no.Text, name_st.Text, dept.Text, dcode.Text))
            maxRoll = maxRoll + 1
            Me.Close()
        End If
    End Sub
End Class